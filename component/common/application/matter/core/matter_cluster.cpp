#include "matter_cluster.h"

Cluster::Cluster(config_t config, uint32_t _cluster_id)
{
    /* common */
    ameba_matter_attr_val_t cluster_revision_value;

    /* identify */
    ameba_matter_attr_val_t identify_time_value;
    ameba_matter_attr_val_t identify_type_value;

    /* groups */
    ameba_matter_attr_val_t group_name_support_value;

    /* scenes */
    ameba_matter_attr_val_t scene_count_value;
    ameba_matter_attr_val_t current_scene_value;
    ameba_matter_attr_val_t current_group_value;
    ameba_matter_attr_val_t scene_valid_value;
    ameba_matter_attr_val_t scene_name_support_value;

    /* on_off */
    ameba_matter_attr_val_t onoff_value;

    /* level_control */
    ameba_matter_attr_val_t current_level_value;
    ameba_matter_attr_val_t on_level_value;
    ameba_matter_attr_val_t options_value;

    /* basic_information */
    ameba_matter_attr_val_t node_label_value;

    /* general_commissioning */
    ameba_matter_attr_val_t breadcrumb_value;

    /* network_commissioning */

    /*general_diagnostics */

    /* administrator_commissioning */

    /* operational_credentials */

    /* diagnostics_network_thread */
    
    /* diagnostics_network_wifi */

    switch (_cluster_id)
    {
    case AMEBA_MATTER_IDENTIFY_CLUSTER_ID:
        printf("identify cluster created\n");
        cluster_id = AMEBA_MATTER_IDENTIFY_CLUSTER_ID;
        identify_t identify_config = config.identify;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = identify_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        identify_time_value.type = AMEBA_MATTER_VAL_TYPE_UINT16; 
        identify_time_value.val = identify_config.identify_time;
        Attribute identify_time = new Attribute(identify_time_value);
        add_attribute(identify_time);

        identify_type_value.type = AMEBA_MATTER_VAL_TYPE_UINT8;
        identify_time_value.val = identify_config.identify.type;
        Attribute identify_type = new Attribute(identify_type_value);
        add_attribute(identify_type);

        break;

    case AMEBA_MATTER_GROUPS_CLUSTER_ID:
        printf("groups cluster created\n");
        cluster_id = AMEBA_MATTER_GROUPS_CLUSTER_ID;
        groups_t groups_config = config.groups;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = groups_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        group_name_support_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        group_name_support_value.val = groups_config.group_name_support;
        Attribute group_name_support = new Attribute(group_name_support_value);
        add_attribute(group_name_support);

        break;

    case AMEBA_MATTER_SCENES_CLUSTER_ID:
        printf("scenes cluster created\n");
        cluster_id = AMEBA_MATTER_SCENES_CLUSTER_ID;
        scenes_t scenes_config = config.scenes;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = scenes_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        scene_count_value.type = AMEBA_MATTER_VAL_TYPE_UINT8;
        scene_count_value.val = scenes_config.scene_count;
        Attribute scene_count = new Attribute(scene_count_value);
        add_attribute(scene_count);

        current_scene_value.type = AMEBA_MATTER_VAL_TYPE_UINT8;
        current_scene_value.val = scenes_config.current_scene;
        Attribute current_scene = new Attribute(current_scene_value);
        add_attribute(current_scene);

        current_group_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        current_group_value.val = scenes_config.current_group;
        Attribute current_group = new Attribute(current_group_value);
        add_attribute(current_group);

        scene_valid_value.type = AMEBA_MATTER_VAL_TYPE_BOOLEAN;
        scene_valid_value.val = scenes_config.scene_valid;
        Attribute scene_valid = new Attribute(scene_valid_value);
        add_attribute(scene_valid);

        scene_name_support_value.type = AMEBA_MATTER_VAL_TYPE_UINT8;
        scene_name_support_value.val = scenes_config.scene_name_support;
        Attribute scene_name_support = new Attribute(scene_name_support_value);
        add_attribute(scene_name_support);

        break;

    case AMEBA_MATTER_ON_OFF_CLUSTER_ID:
        printf("on_off cluster created\n");
        cluster_id = AMEBA_MATTER_ON_OFF_CLUSTER_ID;
        on_off_t on_off_config = config.on_off;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = on_off_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        onoff_value.type = AMEBA_MATTER_VAL_TYPE_BOOLEAN;
        onoff_value.val = on_off_config.onoff;
        Attribute onoff = new Attribute(onoff_value);
        add_attribute(onoff);

        break;

    case AMEBA_MATTER_LEVEL_CONTROL_CLUSTER_ID:
        printf("level_control cluster created\n");
        cluster_id = AMEBA_MATTER_LEVEL_CONTROL_CLUSTER_ID;
        level_control_t level_control_config = config.level_control;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = level_control_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        current_level_value.type = AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT8;
        current_level_value.val = level_control_config.current_level;
        Attribute current_level = new Attribute(current_level_value);
        add_attribute(current_level);

        on_level_value.type = AMEBA_MATTER_VAL_TYPE_NULLABLE_UINT8;
        on_level_value.val = level_control_config.on_level;
        Attribute on_level = new Attribute(on_level_value);
        add_attribute(on_level);

        options_value.type = AMEBA_MATTER_VAL_TYPE_UINT8;
        options_value.val = level_control_config.options;
        Attribute options = new Attribute(options_value);
        add_attribute(options);

        break;

    case AMEBA_MATTER_BASIC_INFORMATION_CLUSTER_ID:
        printf("basic_information cluster created\n");
        cluster_id = AMEBA_MATTER_BASIC_INFORMATION_CLUSTER_ID;
        basic_information_t basic_information_config = config.basic_information;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = basic_information_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        node_label_value.type = AMEBA_MATTER_VAL_TYPE_CHAR_STRING;
        node_label_value.val = basic_information_config.node_label;
        Attribute node_label = new Attribute(node_label_value);
        add_attribute(node_label);

        break;

    case AMEBA_MATTER_GENERAL_COMMISSIONING_CLUSTER_ID:
        printf("general_commissioning cluster created\n");
        cluster_id = AMEBA_MATTER_GENERAL_COMMISSIONING_CLUSTER_ID;
        general_commissioning_t general_commissioning_config = config.general_commissioning;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = general_commissioning_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        breadcrumb_value.type = AMEBA_MATTER_VAL_TYPE_UINT64;
        breadcrumb_value.val = general_commissioning_config.breadcrumb;
        Attribute breadcrumb = new Attribute(breadcrumb_value);
        add_attribute(breadcrumb);

        break;

    case AMEBA_MATTER_NETWORK_COMMISSIONING_CLUSTER_ID:
        printf("network_commissioning cluster created\n");
        cluster_id = AMEBA_MATTER_NETWORK_COMMISSIONING_CLUSTER_ID;
        network_commissioning_t network_commissioning_config = config.network_commissioning;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = network_commissioning_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        break;

    case AMEBA_MATTER_GENERAL_DIAGNOSTICS_CLUSTER_ID:
        printf("general_diagnostics cluster created\n");
        cluster_id = AMEBA_MATTER_GENERAL_DIAGNOSTICS_CLUSTER_ID;
        general_diagnostics_t general_diagnostics_config = config.general_diagnostics;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = general_diagnostics_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        break;

#if 0 // thread enabled
    case AMEBA_MATTER_DIAGNOSTICS_NETWORK_THREAD_CLUSTER_ID:
        printf("diagnostics_network_thread cluster created\n");
        cluster_id = AMEBA_MATTER_DIAGNOSTICS_NETWORK_THREAD_CLUSTER_ID;
        diagnostics_network_thread_t diagnostics_network_thread_config = config.diagnostics_network_thread;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = diagnostics_network_thread_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        break;
#endif

#if 1 // wifi enabled
    case AMEBA_MATTER_DIAGNOSTICS_NETWORK_WIFI_CLUSTER_ID:
        printf("diagnostics_network_wifi cluster created\n");
        cluster_id = AMEBA_MATTER_DIAGNOSTICS_NETWORK_WIFI_CLUSTER_ID;
        diagnostics_network_wifi_t diagnostics_network_wifi_config = config.diagnostics_network_wifi;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = diagnostics_network_wifi_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        break;
#endif

    case AMEBA_MATTER_ADMINISTRATOR_COMMISSIONING_CLUSTER_ID:
        printf("administrator_commissioning cluster created\n");
        cluster_id = AMEBA_MATTER_ADMINISTRATOR_COMMISSIONING_CLUSTER_ID;
        administrator_commissioning_t administrator_commissioning_config = config.administrator_commissioning;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = administrator_commissioning_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        break;

    case AMEBA_MATTER_OPERATIONAL_CREDENTIALS_CLUSTER_ID:
        printf("operational_credentials cluster created\n");
        cluster_id = AMEBA_MATTER_OPERATIONAL_CREDENTIALS_CLUSTER_ID;
        operational_credentials_t operational_credentials_config = config.operational_credentials;

        cluster_revision_value.type = AMEBA_MATTER_VAL_TYPE_UINT16;
        cluster_revision_value.val = operational_credentials_config.cluster_revision;
        Attribute cluster_revision = new Attribute(cluster_revision_value);
        add_attribute(cluster_revision);

        break;
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
