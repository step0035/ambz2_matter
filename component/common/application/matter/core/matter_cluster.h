#include <platform_stdlib.h>
#include "matter_attribute.h"
#include "matter_config.h"

class Cluster
{
public:
    Cluster(config_t config, uint32_t _cluster_id); // create
    // ~ Cluster(); // destroy
    Cluster *get_next(void);
    void set_next(Cluster *cluster);
    uint32_t cluster_id;

private:
    Cluster *next = NULL;
    Attribute *attribute_list = NULL;
};
