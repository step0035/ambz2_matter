#include "matter_node.h"
#include "matter_config.h"
#include "matter_endpoint.h"

void Node::add_endpoint(Endpoint *endpoint)
{
    endpoint->endpoint_id = min_unused_endpoint_id++;
    Endpoint *previous_endpoint = NULL;
    Endpoint *current_endpoint = endpoint_list;
    while (current_endpoint)
    {
        previous_endpoint = current_endpoint;
        current_endpoint = current_endpoint->get_next();
    }
    if (previous_endpoint == NULL)
    {
        endpoint_list = endpoint;
    }
    else
    {
        previous_endpoint->set_next(endpoint);
    }
}
