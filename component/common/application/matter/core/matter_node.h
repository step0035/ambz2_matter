# pragma once

#include <platform_stdlib.h>
#include "matter_config.h"
#include "matter_endpoint.h"

class Node
{
public:
    // Node(Callback attribute_callback, Callback identify_callback); // create
    // ~ Node(); // destroy
    void add_endpoint(Endpoint *endpoint);
    Endpoint *endpoint_list = NULL;
    uint16_t min_unused_endpoint_id = 0;

private:
};
