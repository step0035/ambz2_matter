#include "matter_endpoint.h"
#include "matter_flags.h"

using namespace chip::app::Clusters;

Endpoint::Endpoint(config_t config, uint16_t endpoint_flags)
{
    flags = endpoint_flags;

    if (config.identify.enabled)
    {
        Cluster *identify = new Cluster(config, Identify::Id, endpoint_id, (config.identify.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(identify);
    }
    if (config.groups.enabled)
    {
        Cluster *groups = new Cluster(config, Groups::Id, endpoint_id, (config.groups.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(groups);
    }
    if (config.scenes.enabled)
    {
        Cluster *scenes = new Cluster(config, Scenes::Id, endpoint_id, (config.scenes.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(scenes);
    }
    if (config.on_off.enabled)
    {
        Cluster *on_off = new Cluster(config, OnOff::Id, endpoint_id, (config.on_off.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(on_off);
    }
    if (config.level_control.enabled)
    {
        Cluster *level_control = new Cluster(config, LevelControl::Id, endpoint_id, (config.level_control.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(level_control);
    }
    if (config.basic_information.enabled)
    {
        Cluster *basic_information = new Cluster(config, BasicInformation::Id, endpoint_id, (config.basic_information.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(basic_information);
    }
    if (config.general_commissioning.enabled)
    {
        Cluster *general_commissioning = new Cluster(config, GeneralCommissioning::Id, endpoint_id, (config.general_commissioning.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(general_commissioning);
    }
    if (config.network_commissioning.enabled)
    {
        Cluster *network_commissioning = new Cluster(config, NetworkCommissioning::Id, endpoint_id, (config.network_commissioning.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(network_commissioning);
    }
    if (config.general_diagnostics.enabled)
    {
        Cluster *general_diagnostics = new Cluster(config, GeneralDiagnostics::Id, endpoint_id, (config.general_diagnostics.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(general_diagnostics);
    }
#if 0 // thread enabled
    if (config.diagnostics_network_thread.enabled)
    {
        Cluster *diagnostics_network_thread = new Cluster(config, ThreadNetworkDiagnostics::Id, endpoint_id, (config.diagnostics_network_thread.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(diagnostics_network_thread);
    }
#endif
#if 1 // wifi enabled
    if (config.diagnostics_network_wifi.enabled)
    {
        Cluster *diagnostics_network_wifi = new Cluster(config, WiFiNetworkDiagnostics::Id, endpoint_id, (config.diagnostics_network_wifi.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(diagnostics_network_wifi);
    }
#endif
    if (config.administrator_commissioning.enabled)
    {
        Cluster *administrator_commissioning = new Cluster(config, AdministratorCommissioning::Id, endpoint_id, (config.administrator_commissioning.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
        add_cluster(administrator_commissioning);
    }
    if (config.operational_credentials.enabled)
    {
        Cluster *operational_credentials = new Cluster(config, OperationalCredentials::Id, endpoint_id, (config.operational_credentials.server) ? CLUSTER_FLAG_SERVER : CLUSTER_FLAG_CLIENT);
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

Cluster *Endpoint::get_cluster_by_id(uint32_t cluster_id)
{
    Cluster *current_cluster = cluster_list;
    while (current_cluster)
    {
        if (current_cluster->cluster_id == cluster_id)
        {
            break;
        }
        current_cluster = current_cluster->get_next();
    }
    return current_cluster;
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

int8_t Endpoint::add_device_type(uint32_t device_type_id, uint8_t device_type_version)
{
    if (device_type_count >= AMEBA_MATTER_MAX_DEVICE_TYPE_COUNT)
    {
        printf("Max device type count reached, failed to add device type: %d\n", device_type_id);
        return -1;
    }

    device_type_ids[device_type_count] = device_type_id;
    device_type_versions[device_type_count] = device_type_version;
    device_type_count++;
    return 0;
}
