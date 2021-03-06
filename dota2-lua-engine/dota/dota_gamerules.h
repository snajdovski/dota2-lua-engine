// Copyright 2013 Karl Skomski - GPL v3
#pragma once

#include "source-sdk/netvar.h"
#include "source-sdk/global_instance_manager.h"
#include "utils/global_address_retriever.h"
#include "dota/dota_item.h"
#include "dota/dota_units.h"

namespace dota {

class GameRules {
 public:
  static GameRules* GetInstance() {
    return *reinterpret_cast<GameRules**>(
      GlobalAddressRetriever::GetInstance().GetDynamicAddress("GameRules"));
  }
  float GetGameTime() {
    int offset = sourcesdk::NetVarManager::GetInstance()
      .GetNetVarOffsetL(
        "DT_DOTAGamerulesProxy",
        "dota_gamerules_data",
        "m_fGameTime");
    return *reinterpret_cast<float*>(this + offset);
  }
  UnitAnnouncer* GetAnnouncer(int team_index) {
    uint32_t address = GlobalAddressRetriever::GetInstance()
      .GetStaticAddress("GameRules::GetAnnouncer");
    UnitAnnouncer* announcer;

    __asm {
      push team_index
      mov ecx, this
      call address
      mov announcer, eax
    }

    return announcer;
  }
  UnitAnnouncer* GetKillingSpreeAnnouncer(int team_index) {
    uint32_t address = GlobalAddressRetriever::GetInstance()
      .GetStaticAddress("GameRules::GetKillingSpreeAnnouncer");

    UnitAnnouncer* announcer;

    __asm {
      push team_index
      mov ecx, this
      call address
      mov announcer, eax
    }

    return announcer;
  }
};

}  // namespace dota
