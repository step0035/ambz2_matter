#include "matter_endpoint.h"

Endpoint::Endpoint(config_t config)
{
    if (config.identify.enabled)
    {
        Cluster *identify = new Cluster(config, AMEBA_MATTER_IDENTIFY_CLUSTER_ID);
        add_cluster(identify);
    }
    if (config.groups.enabled)
    {
        Cluster *groups = new Cluster(config, AMEBA_MATTER_GROUPS_CLUSTER_ID);
        add_cluster(groups);
    }
    if (config.scenes.enabled)
    {
        Cluster *scenes = new Cluster(config, AMEBA_MATTER_SCENES_CLUSTER_ID);
        add_cluster(scenes);
    }
    if (config.on_off.enabled)
    {
        Cluster *on_off = new Cluster(config, AMEBA_MATTER_ON_OFF_CLUSTER_ID);
        add_cluster(on_off);
    }
    if (config.level_control.enabled)
    {
        Cluster *level_control = new Cluster(config, AMEBA_MATTER_LEVEL_CONTROL_CLUSTER_ID);
        add_cluster(level_control);
    }
    if (config.basic_information.enabled)
    {
        Cluster *basic_information = new Cluster(config, AMEBA_MATTER_BASIC_INFORMATION_CLUSTER_ID);
        add_cluster(basic_information);
    }
    if (config.general_commissioning.enabled)
    {
        Cluster *general_commissioning = new Cluster(config, AMEBA_MATTER_GENERAL_COMMISSIONING_CLUSTER_ID);
        add_cluster(general_commissioning);
    }
    if (config.network_commissioning.enabled)
    {
        Cluster *network_commissioning = new Cluster(config, AMEBA_MATTER_NETWORK_COMMISSIONING_CLUSTER_ID);
        add_cluster(network_commissioning);
    }
    if (config.general_diagnostics.enabled)
    {
        Cluster *general_diagnostics = new Cluster(config, AMEBA_MATTER_GENERAL_DIAGNOSTICS_CLUSTER_ID);
        add_cluster(general_diagnostics);
    }
#if 0 // thread enabled
    if (config.diagnostics_network_thread.enabled)
    {
        Cluster *diagnostics_network_thread = new Cluster(config, AMEBA_MATTER_DIAGNOSTICS_NETWORK_THREAD_CLUSTER_ID);
        add_cluster(diagnostics_network_thread);
    }
#endif
#if 1 // wifi enabled
    if (config.diagnostics_network_wifi.enabled)
    {
        Cluster *diagnostics_network_wifi = new Cluster(config, AMEBA_MATTER_DIAGNOSTICS_NETWORK_WIFI_CLUSTER_ID);
        add_cluster(diagnostics_network_wifi);
    }
#endif
    if (config.administrator_commissioning.enabled)
    {
        Cluster *administrator_commissioning = new Cluster(config, AMEBA_MATTER_ADMINISTRATOR_COMMISSIONING_CLUSTER_ID);
        add_cluster(administrator_commissioning);
    }
    if (config.operational_credentials.enabled)
    {
        Cluster *operational_credentials = new Cluster(config, AMEBA_MATTER_OPERATIONAL_CREDENTIALS_CLUSTER_ID);
        add_cluster(operational_credentials);
    }
}

Endpoint *Endpoint::get_next()
{
    return next;
}

void Endpoint::set_next(Endpoint *endpoint)
{
    next = endpoint;
}

void Endpoint::add_cluster(Cluster *cluster)
{
    Cluster *previous_cluster = NULL;
    Cluster *current_cluster = cluster_list;
    while (current_cluster)
    {
        previous_cluster = current_cluster;
        current_cluster = current_cluster->get_next();
    }
    if (previous_cluster == NULL)
    {
        cluster_list = cluster;
    }
    else
    {
        previous_cluster->set_next(cluster);
    }
}
