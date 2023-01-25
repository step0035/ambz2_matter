#pragma once

#include <platform_stdlib.h>
#include "matter_config.h"
#include "matter_cluster.h"

// class Endpoint
// {
// public:
//     Endpoint(config_t config); // create
//     // ~ Endpoint(); // destroy
//     Endpoint *get_next(void);
//     void set_next(Endpoint *endpoint);
//     uint16_t endpoint_id;

// protected:
//     Endpoint *next = NULL;
//     Cluster *cluster_list;
// };

#define AMEBA_MATTER_MAX_DEVICE_TYPE_COUNT  16
class Endpoint
{
public:
    Endpoint(config_t config, uint16_t endpoint_flags); // create
    // ~ Endpoint(); // destroy
    Endpoint *get_next(void);
    void set_next(Endpoint *endpoint);
    Cluster *get_cluster_by_id(uint32_t cluster_id);
    void add_cluster(Cluster *cluster);
    int8_t add_device_type(uint32_t device_type_id, uint8_t device_type_version);
    uint16_t endpoint_id;
    uint8_t device_type_count;
    uint32_t device_type_ids[16];
    uint32_t device_type_versions[16];
    uint16_t flags;
    Cluster *cluster_list = NULL;

protected:
    Endpoint *next = NULL;
};
