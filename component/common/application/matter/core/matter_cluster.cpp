#include "matter_cluster.h"

using namespace chip::app::Clusters;

Cluster::Cluster(config_t config, uint32_t _cluster_id, uint16_t cluster_flags)
{
    flags = cluster_flags;

    if (_cluster_id == Identify::Id)
    {
        printf("identify cluster created\n");
        cluster_id = Identify::Id;
        identify_t identify_config = config.identify;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(identify_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *identify_time = new Attribute(ameba_matter_uint16(identify_config.identify_time), Identify::Attributes::IdentifyTime::Id);
        add_attribute(identify_time);

        Attribute *identify_type = new Attribute(ameba_matter_uint8(identify_config.identify_type), Identify::Attributes::IdentifyType::Id);
        add_attribute(identify_type);
    }

    else if (_cluster_id == Groups::Id)
    {
        printf("groups cluster created\n");
        cluster_id = Groups::Id;
        groups_t groups_config = config.groups;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(groups_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *group_name_support = new Attribute(ameba_matter_uint16(groups_config.group_name_support), Groups::Attributes::NameSupport::Id);
        add_attribute(group_name_support);
    }

    else if (_cluster_id == Scenes::Id)
    {
        printf("scenes cluster created\n");
        cluster_id = Scenes::Id;
        scenes_t scenes_config = config.scenes;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(scenes_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *scene_count = new Attribute(ameba_matter_uint8(scenes_config.scene_count), Scenes::Attributes::SceneCount::Id);
        add_attribute(scene_count);

        Attribute *current_scene = new Attribute(ameba_matter_uint8(scenes_config.current_scene), Scenes::Attributes::CurrentScene::Id);
        add_attribute(current_scene);

        Attribute *current_group = new Attribute(ameba_matter_uint16(scenes_config.current_group), Scenes::Attributes::CurrentGroup::Id);
        add_attribute(current_group);

        Attribute *scene_valid = new Attribute(ameba_matter_bool(scenes_config.scene_valid), Scenes::Attributes::SceneValid::Id);
        add_attribute(scene_valid);

        Attribute *scene_name_support = new Attribute(ameba_matter_uint8(scenes_config.scene_name_support), Scenes::Attributes::NameSupport::Id);
        add_attribute(scene_name_support);
    }

    else if (_cluster_id == OnOff::Id)
    {
        printf("on_off cluster created\n");
        cluster_id = OnOff::Id;
        on_off_t on_off_config = config.on_off;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(on_off_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *onoff = new Attribute(ameba_matter_bool(on_off_config.onoff), OnOff::Attributes::OnOff::Id);
        add_attribute(onoff);
    }

    else if (_cluster_id == LevelControl::Id)
    {
        printf("level_control cluster created\n");
        cluster_id = LevelControl::Id;
        level_control_t level_control_config = config.level_control;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(level_control_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *current_level = new Attribute(ameba_matter_nullable_uint8(level_control_config.current_level), LevelControl::Attributes::CurrentLevel::Id);
        add_attribute(current_level);

        Attribute *on_level = new Attribute(ameba_matter_nullable_uint8(level_control_config.on_level), LevelControl::Attributes::OnLevel::Id);
        add_attribute(on_level);

        Attribute *options = new Attribute(ameba_matter_uint8(level_control_config.options), LevelControl::Attributes::Options::Id);
        add_attribute(options);
    }

    else if (_cluster_id == BasicInformation::Id)
    {
        printf("basic_information cluster created\n");
        cluster_id = BasicInformation::Id;
        basic_information_t basic_information_config = config.basic_information;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(basic_information_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *node_label = new Attribute(ameba_matter_char_str(basic_information_config.node_label, sizeof(basic_information_config.node_label)), BasicInformation::Attributes::NodeLabel::Id);
        add_attribute(node_label);
    }

    else if (_cluster_id == GeneralCommissioning::Id)
    {
        printf("general_commissioning cluster created\n");
        cluster_id = GeneralCommissioning::Id;
        general_commissioning_t general_commissioning_config = config.general_commissioning;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(general_commissioning_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);

        Attribute *breadcrumb = new Attribute(ameba_matter_uint64(general_commissioning_config.breadcrumb), GeneralCommissioning::Attributes::Breadcrumb::Id);
        add_attribute(breadcrumb);
    }

    else if (_cluster_id == NetworkCommissioning::Id)
    {
        printf("network_commissioning cluster created\n");
        cluster_id = NetworkCommissioning::Id;
        network_commissioning_t network_commissioning_config = config.network_commissioning;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(network_commissioning_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);
    }

    else if (_cluster_id == GeneralDiagnostics::Id)
    {
        printf("general_diagnostics cluster created\n");
        cluster_id = GeneralDiagnostics::Id;
        general_diagnostics_t general_diagnostics_config = config.general_diagnostics;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(general_diagnostics_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);
    }

#if 0 // thread enabled
    else if (_cluster_id == ThreadNetworkDiagnostics::Id)
    {
        printf("diagnostics_network_thread cluster created\n");
        cluster_id = ThreadNetworkDiagnostics::Id;
        diagnostics_network_thread_t diagnostics_network_thread_config = config.diagnostics_network_thread;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(diagnostics_network_thread_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);
    }
#endif

#if 1 // wifi enabled
    else if (_cluster_id == WiFiNetworkDiagnostics::Id)
    {
        printf("diagnostics_network_wifi cluster created\n");
        cluster_id = WiFiNetworkDiagnostics::Id;
        diagnostics_network_wifi_t diagnostics_network_wifi_config = config.diagnostics_network_wifi;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(diagnostics_network_wifi_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);
    }
#endif

    else if (_cluster_id == AdministratorCommissioning::Id)
    {
        printf("administrator_commissioning cluster created\n");
        cluster_id = AdministratorCommissioning::Id;
        administrator_commissioning_t administrator_commissioning_config = config.administrator_commissioning;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(administrator_commissioning_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);
    }

    else if (_cluster_id == OperationalCredentials::Id)
    {
        printf("operational_credentials cluster created\n");
        cluster_id = OperationalCredentials::Id;
        operational_credentials_t operational_credentials_config = config.operational_credentials;

        Attribute *cluster_revision = new Attribute(ameba_matter_uint16(operational_credentials_config.cluster_revision), Globals::Attributes::ClusterRevision::Id);
        add_attribute(cluster_revision);
    }
}

Cluster *Cluster::get_next()
{
    return next;
}

void Cluster::set_next(Cluster *cluster)
{
    next = cluster;
}

void Cluster::add_attribute(Attribute *attribute)
{
    Attribute *previous_attribute = NULL;
    Attribute *current_attribute = attribute_list;
    while (current_attribute)
    {
        previous_attribute = current_attribute;
        current_attribute = current_attribute->get_next();
    }
    if (previous_attribute == NULL)
    {
        attribute_list = attribute;
    }
    else
    {
        previous_attribute->set_next(attribute);
    }
}
