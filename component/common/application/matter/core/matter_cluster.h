#pragma once

#include <platform_stdlib.h>
#include "matter_attribute.h"
#include "matter_command.h"
#include "matter_config.h"

typedef void (*plugin_server_init_callback_t)();
typedef void (*plugin_client_init_callback_t)();
void plugin_init_callback_common(void);

class Cluster
{
public:
    Cluster(config_t config, uint32_t _cluster_id, uint16_t cluster_flags); // create
    // ~ Cluster(); // destroy
    Cluster *get_next(void);
    void set_next(Cluster *cluster);
    Attribute *get_attribute_by_id(uint32_t attribute_id);
    Command *get_command_by_id(uint32_t command_id, uint16_t command_flags);
    void add_attribute(Attribute *attribute);
    void add_command(Command *command);
    uint32_t cluster_id;
    Cluster *next = NULL;
    Attribute *attribute_list = NULL;
    Command *command_list = NULL;
    Cluster *cluster_list = NULL;
    uint16_t flags;
    void set_plugin_server_init_callback(plugin_server_init_callback_t callback);
    void set_plugin_client_init_callback(plugin_client_init_callback_t callback);
    plugin_server_init_callback_t get_plugin_server_init_callback(void);
    plugin_client_init_callback_t get_plugin_client_init_callback(void);
    plugin_server_init_callback_t plugin_server_init_callback;
    plugin_client_init_callback_t plugin_client_init_callback;
};
