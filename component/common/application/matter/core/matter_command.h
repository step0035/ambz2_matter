#pragma once

#include <platform_stdlib.h>
#include <app/InteractionModelEngine.h>

using chip::app::ConcreteCommandPath;
using chip::TLV::TLVReader;

typedef int8_t (*callback_t)(const ConcreteCommandPath &command_path, TLVReader &tlv_data, void *opaque_ptr);

class Command
{
public:
    // TODO: add callback
    Command(uint32_t command_id, uint16_t command_flags, callback_t command_callback);
    ~ Command();
    uint32_t id;
    uint16_t flags;
    Command *next;
    Command *get_next(void);
    void set_next(Command *command);
    callback_t callback;

private:
};

