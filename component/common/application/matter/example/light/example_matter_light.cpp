#include "FreeRTOS.h"
#include "task.h"
#include "platform/platform_stdlib.h"
#include "basic_types.h"
#include "platform_opts.h"
#include "section_config.h"
#include "wifi_constants.h"
#include "wifi/wifi_conf.h"
#include "chip_porting.h"
#include "matter_core.h"
#include "matter_drivers.h"
#include "matter_interaction.h"
#include "matter_config.h"
#include "matter_node.h"
#include "matter_flags.h"

void configure_endpoint_config(uint16_t device_type, config_t *config)
{
    switch (device_type)
    {
    case AMEBA_MATTER_ROOT_NODE_DEVICE_TYPE_ID:
        config->basic_information.enabled = true;
        config->general_commissioning.enabled = true;
        config->network_commissioning.enabled = true;
        config->general_diagnostics.enabled = true;
        config->administrator_commissioning.enabled = true;
        config->operational_credentials.enabled = true;
#if 0 // thread enabled
        config->diagnostics_network_thread.enabled = true;
#endif
#if 1 // wifi enabled
        config->diagnostics_network_wifi.enabled = true;
#endif
        break;

    case AMEBA_MATTER_ON_OFF_LIGHT_DEVICE_TYPE_ID:
        config->identify.enabled = true;
        config->groups.enabled = true;
        config->scenes.enabled = true;
        config->on_off.enabled = true;
        break;

    case AMEBA_MATTER_DIMMABLE_LIGHT_DEVICE_TYPE_ID:
        config->identify.enabled = true;
        config->groups.enabled = true;
        config->scenes.enabled = true;
        config->on_off.enabled = true;
        config->level_control.enabled = true;
        break;
    }
}

static void example_matter_light_task(void *pvParameters)
{
    // // TODO: error checking
    // // TODO: set default led values
    // while(!(wifi_is_up(RTW_STA_INTERFACE) || wifi_is_up(RTW_AP_INTERFACE))) {
    //     //waiting for Wifi to be initialized
    // }

    // CHIP_ERROR err = CHIP_NO_ERROR;

    // initPref();     // init NVS
    // //
    // err = matter_core_start();
    // if (err != CHIP_NO_ERROR)
    //     printf("matter_core_start failed!\n");

    // err = matter_driver_led_init();
    // if (err != CHIP_NO_ERROR)
    //     printf("matter_driver_led_init failed!\n");

    // err = matter_driver_led_set_startup_value();
    // if (err != CHIP_NO_ERROR)
    //     printf("matter_driver_led_set_startup_value failed!\n");

    // err = matter_driver_button_init();
    // if (err != CHIP_NO_ERROR)
    //     printf("matter_driver_button_init failed!\n");

    // err = matter_interaction_start_downlink();
    // if (err != CHIP_NO_ERROR)
    //     printf("matter_interaction_start_downlink failed!\n");

    // err = matter_interaction_start_uplink();
    // if (err != CHIP_NO_ERROR)
    //     printf("matter_interaction_start_uplink failed!\n");

    // while(1);

    while(!(wifi_is_up(RTW_STA_INTERFACE) || wifi_is_up(RTW_AP_INTERFACE))) {
        //waiting for Wifi to be initialized
    }

    printf("\nLighting-app Example\n");

    /* Node creation */
    Node *node = new Node;

    /* Endpoint creation */
    config_t root_node_config;
    configure_endpoint_config(AMEBA_MATTER_ROOT_NODE_DEVICE_TYPE_ID, &root_node_config);
    Endpoint *root_node = new Endpoint(root_node_config, ENDPOINT_FLAG_NONE);

    config_t light_config;
    configure_endpoint_config(AMEBA_MATTER_ON_OFF_LIGHT_DEVICE_TYPE_ID, &light_config);
    light_config.on_off.onoff = true;
    Endpoint *on_off_light = new Endpoint(light_config, ENDPOINT_FLAG_NONE);

    /* Add endpoints */
    node->add_endpoint(root_node);
    node->add_endpoint(on_off_light);

    /* Checks */
    Endpoint *test_endpoint = node->endpoint_list;
    while(test_endpoint)
    {
        printf("Endpoint ID %d clusters:\n", test_endpoint->endpoint_id);
        Cluster *test_cluster = test_endpoint->cluster_list;
        while(test_cluster)
        {
            printf("\tCluster ID: %d\n", test_cluster->cluster_id);
            Attribute *test_attribute = test_cluster->attribute_list;
            while(test_attribute)
            {
                printf("\t\tAttribute ID: %d\n", test_attribute->attribute_id);
                test_attribute = test_attribute->get_next();
            }
            test_cluster = test_cluster->get_next();
        }
        test_endpoint = test_endpoint->get_next(); 
    }

    vTaskDelete(NULL);
}

extern "C" void example_matter_light(void)
{
    if(xTaskCreate(example_matter_light_task, ((const char*)"example_matter_task_thread"), 2048, NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS)
        printf("\n\r%s xTaskCreate(example_matter_light) failed", __FUNCTION__);
}
