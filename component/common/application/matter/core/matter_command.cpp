#include "matter_command.h"
#include "matter_flags.h"
#include "matter_node.h"
#include <app/util/ember-compatibility-functions.h>

extern Node *node;

void DispatchSingleClusterCommandCommon(const ConcreteCommandPath &command_path, TLVReader &tlv_data, void *opaque_ptr)
{
    uint16_t endpoint_id = command_path.mEndpointId;
    uint32_t cluster_id = command_path.mClusterId;
    uint32_t command_id = command_path.mCommandId;
    printf("Received command 0x%04X for enpoint 0x%04X's cluster 0x%08X\n", command_id, endpoint_id, cluster_id);

    Endpoint *endpoint = node->get_endpoint_by_id(endpoint_id);
    Cluster *cluster = endpoint->get_cluster_by_id(cluster_id);
    Command *command = cluster->get_command_by_id(command_id, COMMAND_FLAG_ACCEPTED);
    if (!command) 
    {
        printf("Command 0x%04X not found\n", command_id);
        return;
    }
    int8_t err = 0;
    callback_t callback = command->callback; // TODO: use getter
    if(callback)
    {
        err = callback(command_path, tlv_data, opaque_ptr);
    }
    int flags = command->flags; // TODO: use getter
    if (flags & COMMAND_FLAG_CUSTOM)
    {
        EmberAfStatus status = (err == 0) ? EMBER_ZCL_STATUS_SUCCESS : EMBER_ZCL_STATUS_FAILURE;
        emberAfSendImmediateDefaultResponse(status);
    }
}

namespace chip {
namespace app {

void DispatchSingleClusterCommand(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                  CommandHandler *command_obj)
{
    Compatibility::SetupEmberAfCommandHandler(command_obj, command_path);

    DispatchSingleClusterCommandCommon(command_path, tlv_data, command_obj);

    Compatibility::ResetEmberAfObjects();
}

} /* namespace app */
} /* namespace chip */


Command::Command(uint32_t _command_id, uint32_t _cluster_id, uint32_t _endpoint_id, uint16_t command_flags, callback_t command_callback)
{
    endpoint_id = _endpoint_id;
    cluster_id = _cluster_id;
    command_id = _command_id;
    flags = command_flags;
    callback = command_callback;
}

Command *Command::get_next(void)
{
    return next;
}

void Command::set_next(Command *command)
{
    next = command;
}
