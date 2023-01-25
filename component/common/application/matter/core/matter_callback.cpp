#include "matter_callback.h"

int8_t ameba_matter_command_callback_key_set_write(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                           void *opaque_ptr)
{
    chip::app::Clusters::GroupKeyManagement::Commands::KeySetWrite::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupKeyManagementClusterKeySetWriteCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_key_set_read(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                          void *opaque_ptr)
{
    chip::app::Clusters::GroupKeyManagement::Commands::KeySetRead::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupKeyManagementClusterKeySetReadCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_key_set_remove(const ConcreteCommandPath &command_path,
                                                            TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::GroupKeyManagement::Commands::KeySetRemove::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupKeyManagementClusterKeySetRemoveCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_key_set_read_all_indices(const ConcreteCommandPath &command_path,
                                                                      TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::GroupKeyManagement::Commands::KeySetReadAllIndices::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupKeyManagementClusterKeySetReadAllIndicesCallback((CommandHandler *)opaque_ptr, command_path,
                                                                     command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_arm_fail_safe(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                           void *opaque_ptr)
{
    chip::app::Clusters::GeneralCommissioning::Commands::ArmFailSafe::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGeneralCommissioningClusterArmFailSafeCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_set_regulatory_config(const ConcreteCommandPath &command_path,
                                                                   TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::GeneralCommissioning::Commands::SetRegulatoryConfig::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGeneralCommissioningClusterSetRegulatoryConfigCallback((CommandHandler *)opaque_ptr, command_path,
                                                                      command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_commissioning_complete(const ConcreteCommandPath &command_path,
                                                                    TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::GeneralCommissioning::Commands::CommissioningComplete::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGeneralCommissioningClusterCommissioningCompleteCallback((CommandHandler *)opaque_ptr, command_path,
                                                                        command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_scan_networks(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                           void *opaque_ptr)
{
    chip::app::Clusters::NetworkCommissioning::Commands::ScanNetworks::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfNetworkCommissioningClusterScanNetworksCallback((CommandHandler *)opaque_ptr, command_path,
                                                               command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_or_update_wifi_network(const ConcreteCommandPath &command_path,
                                                                        TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::NetworkCommissioning::Commands::AddOrUpdateWiFiNetwork::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfNetworkCommissioningClusterAddOrUpdateWiFiNetworkCallback((CommandHandler *)opaque_ptr, command_path,
                                                                         command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_or_update_thread_network(const ConcreteCommandPath &command_path,
                                                                          TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::NetworkCommissioning::Commands::AddOrUpdateThreadNetwork::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfNetworkCommissioningClusterAddOrUpdateThreadNetworkCallback((CommandHandler *)opaque_ptr, command_path,
                                                                           command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_remove_network(const ConcreteCommandPath &command_path,
                                                            TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::NetworkCommissioning::Commands::RemoveNetwork::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfNetworkCommissioningClusterRemoveNetworkCallback((CommandHandler *)opaque_ptr, command_path,
                                                                command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_connect_network(const ConcreteCommandPath &command_path,
                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::NetworkCommissioning::Commands::ConnectNetwork::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfNetworkCommissioningClusterConnectNetworkCallback((CommandHandler *)opaque_ptr, command_path,
                                                                 command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_reorder_network(const ConcreteCommandPath &command_path,
                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::NetworkCommissioning::Commands::ReorderNetwork::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfNetworkCommissioningClusterReorderNetworkCallback((CommandHandler *)opaque_ptr, command_path,
                                                                 command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_open_commissioning_window(const ConcreteCommandPath &command_path,
                                                                       TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::AdministratorCommissioning::Commands::OpenCommissioningWindow::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfAdministratorCommissioningClusterOpenCommissioningWindowCallback((CommandHandler *)opaque_ptr,
                                                                                command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_open_basic_commissioning_window(const ConcreteCommandPath &command_path,
                                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::AdministratorCommissioning::Commands::OpenBasicCommissioningWindow::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfAdministratorCommissioningClusterOpenBasicCommissioningWindowCallback((CommandHandler *)opaque_ptr,
                                                                                     command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_revoke_commissioning(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::AdministratorCommissioning::Commands::RevokeCommissioning::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfAdministratorCommissioningClusterRevokeCommissioningCallback((CommandHandler *)opaque_ptr, command_path,
                                                                            command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_attestation_request(const ConcreteCommandPath &command_path,
                                                                 TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::AttestationRequest::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterAttestationRequestCallback((CommandHandler *)opaque_ptr, command_path,
                                                                       command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_certificate_chain_request(const ConcreteCommandPath &command_path,
                                                                       TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::CertificateChainRequest::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterCertificateChainRequestCallback((CommandHandler *)opaque_ptr, command_path,
                                                                            command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_csr_request(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                         void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::CSRRequest::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterCSRRequestCallback((CommandHandler *)opaque_ptr, command_path,
                                                               command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_noc(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                     void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::AddNOC::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterAddNOCCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_update_noc(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                        void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::UpdateNOC::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterUpdateNOCCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_update_fabric_label(const ConcreteCommandPath &command_path,
                                                                 TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::UpdateFabricLabel::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterUpdateFabricLabelCallback((CommandHandler *)opaque_ptr, command_path,
                                                                      command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_remove_fabric(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                           void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::RemoveFabric::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterRemoveFabricCallback((CommandHandler *)opaque_ptr, command_path,
                                                                 command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_trusted_root_certificate(const ConcreteCommandPath &command_path,
                                                                          TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OperationalCredentials::Commands::AddTrustedRootCertificate::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOperationalCredentialsClusterAddTrustedRootCertificateCallback((CommandHandler *)opaque_ptr,
                                                                              command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_query_image(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                         void *opaque_ptr)
{
    chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::QueryImage::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOtaSoftwareUpdateProviderClusterQueryImageCallback((CommandHandler *)opaque_ptr, command_path,
                                                                  command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_apply_update_request(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::ApplyUpdateRequest::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOtaSoftwareUpdateProviderClusterApplyUpdateRequestCallback((CommandHandler *)opaque_ptr, command_path,
                                                                          command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_notify_update_applied(const ConcreteCommandPath &command_path,
                                                                   TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::NotifyUpdateApplied::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOtaSoftwareUpdateProviderClusterNotifyUpdateAppliedCallback((CommandHandler *)opaque_ptr, command_path,
                                                                           command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_announce_ota_provider(const ConcreteCommandPath &command_path,
                                                                   TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OtaSoftwareUpdateRequestor::Commands::AnnounceOTAProvider::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOtaSoftwareUpdateRequestorClusterAnnounceOTAProviderCallback((CommandHandler *)opaque_ptr, command_path,
                                                                            command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_identify(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                      void *opaque_ptr)
{
    chip::app::Clusters::Identify::Commands::Identify::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfIdentifyClusterIdentifyCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_trigger_effect(const ConcreteCommandPath &command_path,
                                                            TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Identify::Commands::TriggerEffect::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfIdentifyClusterTriggerEffectCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_group(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::Groups::Commands::AddGroup::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupsClusterAddGroupCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_view_group(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                        void *opaque_ptr)
{
    chip::app::Clusters::Groups::Commands::ViewGroup::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupsClusterViewGroupCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_get_group_membership(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Groups::Commands::GetGroupMembership::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupsClusterGetGroupMembershipCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_remove_group(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                          void *opaque_ptr)
{
    chip::app::Clusters::Groups::Commands::RemoveGroup::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupsClusterRemoveGroupCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_remove_all_groups(const ConcreteCommandPath &command_path,
                                                               TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Groups::Commands::RemoveAllGroups::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupsClusterRemoveAllGroupsCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_group_if_identifying(const ConcreteCommandPath &command_path,
                                                                      TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Groups::Commands::AddGroupIfIdentifying::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGroupsClusterAddGroupIfIdentifyingCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_add_scene(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::AddScene::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterAddSceneCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_view_scene(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                        void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::ViewScene::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterViewSceneCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_remove_scene(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                          void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::RemoveScene::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterRemoveSceneCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_remove_all_scenes(const ConcreteCommandPath &command_path,
                                                               TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::RemoveAllScenes::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterRemoveAllScenesCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_store_scene(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                         void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::StoreScene::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterStoreSceneCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_recall_scene(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                          void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::RecallScene::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterRecallSceneCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_get_scene_membership(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Scenes::Commands::GetSceneMembership::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfScenesClusterGetSceneMembershipCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_off(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                 void *opaque_ptr)
{
    chip::app::Clusters::OnOff::Commands::Off::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOnOffClusterOffCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_on(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                void *opaque_ptr)
{
    chip::app::Clusters::OnOff::Commands::On::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOnOffClusterOnCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_toggle(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                    void *opaque_ptr)
{
    chip::app::Clusters::OnOff::Commands::Toggle::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOnOffClusterToggleCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_off_with_effect(const ConcreteCommandPath &command_path,
                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OnOff::Commands::OffWithEffect::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOnOffClusterOffWithEffectCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_on_with_recall_global_scene(const ConcreteCommandPath &command_path,
                                                                         TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OnOff::Commands::OnWithRecallGlobalScene::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOnOffClusterOnWithRecallGlobalSceneCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_on_with_timed_off(const ConcreteCommandPath &command_path,
                                                               TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::OnOff::Commands::OnWithTimedOff::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfOnOffClusterOnWithTimedOffCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_level(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                           void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::MoveToLevel::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterMoveToLevelCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                  void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::Move::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterMoveCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_step(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                  void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::Step::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterStepCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_stop(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                  void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::Stop::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterStopCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_level_with_on_off(const ConcreteCommandPath &command_path,
                                                                       TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::MoveToLevelWithOnOff::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterMoveToLevelWithOnOffCallback((CommandHandler *)opaque_ptr, command_path,
                                                               command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_with_on_off(const ConcreteCommandPath &command_path,
                                                              TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::MoveWithOnOff::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterMoveWithOnOffCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_step_with_on_off(const ConcreteCommandPath &command_path,
                                                              TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::StepWithOnOff::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterStepWithOnOffCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_stop_with_on_off(const ConcreteCommandPath &command_path,
                                                              TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::StopWithOnOff::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterStopWithOnOffCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_closest_frequency(const ConcreteCommandPath &command_path,
                                                                       TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::LevelControl::Commands::MoveToClosestFrequency::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfLevelControlClusterMoveToClosestFrequencyCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_hue(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                         void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveToHue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveToHueCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_hue(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                      void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveHue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveHueCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_step_hue(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                      void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::StepHue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterStepHueCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_saturation(const ConcreteCommandPath &command_path,
                                                                TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveToSaturation::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveToSaturationCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_saturation(const ConcreteCommandPath &command_path,
                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveSaturation::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveSaturationCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_step_saturation(const ConcreteCommandPath &command_path,
                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::StepSaturation::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterStepSaturationCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_hue_and_saturation(const ConcreteCommandPath &command_path,
                                                                        TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveToHueAndSaturation::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveToHueAndSaturationCallback((CommandHandler *)opaque_ptr, command_path,
                                                                 command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_stop_move_step(const ConcreteCommandPath &command_path,
                                                            TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::StopMoveStep::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterStopMoveStepCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_color_temperature(const ConcreteCommandPath &command_path,
                                                                       TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveToColorTemperature::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveToColorTemperatureCallback((CommandHandler *)opaque_ptr, command_path,
                                                                 command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_color_temperature(const ConcreteCommandPath &command_path,
                                                                    TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveColorTemperature::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveColorTemperatureCallback((CommandHandler *)opaque_ptr, command_path,
                                                               command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_step_color_temperature(const ConcreteCommandPath &command_path,
                                                                    TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::StepColorTemperature::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterStepColorTemperatureCallback((CommandHandler *)opaque_ptr, command_path,
                                                               command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_enhanced_move_to_hue(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::EnhancedMoveToHue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterEnhancedMoveToHueCallback((CommandHandler *)opaque_ptr, command_path,
                                                            command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_enhanced_move_hue(const ConcreteCommandPath &command_path,
                                                               TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::EnhancedMoveHue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterEnhancedMoveHueCallback((CommandHandler *)opaque_ptr, command_path,
                                                          command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_enhanced_step_hue(const ConcreteCommandPath &command_path,
                                                               TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::EnhancedStepHue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterEnhancedStepHueCallback((CommandHandler *)opaque_ptr, command_path,
                                                          command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_enhanced_move_to_hue_and_saturation(const ConcreteCommandPath &command_path,
                                                                                 TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::EnhancedMoveToHueAndSaturation::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterEnhancedMoveToHueAndSaturationCallback((CommandHandler *)opaque_ptr, command_path,
                                                                         command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_color_loop_set(const ConcreteCommandPath &command_path,
                                                            TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::ColorLoopSet::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterColorLoopSetCallback((CommandHandler *)opaque_ptr, command_path,
                                                       command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_to_color(const ConcreteCommandPath &command_path,
                                                           TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveToColor::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveToColorCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_move_color(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                        void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::MoveColor::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterMoveColorCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_step_color(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                        void *opaque_ptr)
{
    chip::app::Clusters::ColorControl::Commands::StepColor::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfColorControlClusterStepColorCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_lock_door(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::DoorLock::Commands::LockDoor::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfDoorLockClusterLockDoorCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_unlock_door(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                         void *opaque_ptr)
{
    chip::app::Clusters::DoorLock::Commands::UnlockDoor::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfDoorLockClusterUnlockDoorCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_setpoint_raise_lower(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Thermostat::Commands::SetpointRaiseLower::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfThermostatClusterSetpointRaiseLowerCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_set_weekly_schedule(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Thermostat::Commands::SetWeeklySchedule::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfThermostatClusterSetWeeklyScheduleCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_get_weekly_schedule(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Thermostat::Commands::GetWeeklySchedule::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfThermostatClusterGetWeeklyScheduleCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_clear_weekly_schedule(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::Thermostat::Commands::ClearWeeklySchedule::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfThermostatClusterClearWeeklyScheduleCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_thread_reset_counts(const ConcreteCommandPath &command_path,
                                                                 TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::ThreadNetworkDiagnostics::Commands::ResetCounts::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfThreadNetworkDiagnosticsClusterResetCountsCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_wifi_reset_counts(const ConcreteCommandPath &command_path,
                                                               TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::WiFiNetworkDiagnostics::Commands::ResetCounts::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWiFiNetworkDiagnosticsClusterResetCountsCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_test_event_trigger(const ConcreteCommandPath &command_path,
                                                                  TLVReader &tlv_data, void *opaque_ptr)
{
    chip::app::Clusters::GeneralDiagnostics::Commands::TestEventTrigger::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfGeneralDiagnosticsClusterTestEventTriggerCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_up_or_open(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::UpOrOpen::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterUpOrOpenCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_down_or_close(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::DownOrClose::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterDownOrCloseCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_stop_motion(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::StopMotion::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterStopMotionCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_go_to_lift_value(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::GoToLiftValue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterGoToLiftValueCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_go_to_lift_percentage(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::GoToLiftPercentage::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterGoToLiftPercentageCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_go_to_tilt_value(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::GoToTiltValue::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterGoToTiltValueCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_go_to_tilt_percentage(const ConcreteCommandPath &command_path, TLVReader &tlv_data,
                                                       void *opaque_ptr)
{
    chip::app::Clusters::WindowCovering::Commands::GoToTiltPercentage::DecodableType command_data;
    CHIP_ERROR error = Decode(tlv_data, command_data);
    if (error == CHIP_NO_ERROR) {
        emberAfWindowCoveringClusterGoToTiltPercentageCallback((CommandHandler *)opaque_ptr, command_path, command_data);
    }
    return 0;
}

int8_t ameba_matter_command_callback_instance_action(const ConcreteCommandPath &command_path,
                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_instance_action_with_transition(const ConcreteCommandPath &command_path,
                                                                             TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_start_action(const ConcreteCommandPath &command_path,
                                                          TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_start_action_with_duration(const ConcreteCommandPath &command_path,
                                                                        TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_stop_action(const ConcreteCommandPath &command_path,
                                                         TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_pause_action(const ConcreteCommandPath &command_path,
                                                          TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_pause_action_with_duration(const ConcreteCommandPath &command_path,
                                                                        TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_resume_action(const ConcreteCommandPath &command_path,
                                                           TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_enable_action(const ConcreteCommandPath &command_path,
                                                           TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_enable_action_with_duration(const ConcreteCommandPath &command_path,
                                                                         TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_disable_action(const ConcreteCommandPath &command_path,
                                                            TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}

int8_t ameba_matter_command_callback_disable_action_with_duration(const ConcreteCommandPath &command_path,
                                                                          TLVReader &tlv_data, void *opaque_ptr)
{
    // No actions are implemented, just return status NotFound.
    // TODO: Add action callbacks for actions cluster.
    CommandHandler *command_handler = (CommandHandler *)opaque_ptr;
    command_handler->AddStatus(command_path, chip::Protocols::InteractionModel::Status::NotFound);

    return 0;
}
