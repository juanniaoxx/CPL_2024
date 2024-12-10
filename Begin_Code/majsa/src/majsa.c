#include "majsa.h"

Result *majsa(Status *status) {
  Result *result = (Result *)malloc(sizeof(Result));
  Result example0 = {
      .type = TSUMO,
      .yaku = {Kokushijuusanmenmachi},
      .han = -2,
      .fu = 0,  // 0 代表 OJ 不会测评该条目
      .point = {32000, 32000, 32000},
      .machi = 0,    // 0 代表 OJ 不会测评该条目
      .shanten = 0,  // 0 代表 OJ 不会测评该条目
  };
  Result example1 = {
      .type = RON,
      .yaku = {Tanyao, Riichi, Ippatsu},
      .han = 5,
      .fu = 40,
      .point = {8300, 0, 0},
      .machi = 0,    // 0 代表 OJ 不会测评该条目
      .shanten = 0,  // 0 代表 OJ 不会测评该条目
  };
  Result example2 = {
      .type = RON,
      .yaku = {YakuhaiChun, HonitsuF},
      .han = 4,
      .fu = 40,
      .point = {0, 0, 8300},
      .machi = 0,    // 0 代表 OJ 不会测评该条目
      .shanten = 0,  // 0 代表 OJ 不会测评该条目
  };
  Result example3 = {
      .type = TENPAI,
      .yaku = {},          // 全空代表 OJ 不会测评该条目
      .han = 0,           // 0 代表 OJ 不会测评该条目
      .fu = 0,            // 0 代表 OJ 不会测评该条目
      .point = {0, 0, 0},  // 全为零代表 OJ 不会测评该条目
      .machi = 2,
      .shanten = 0,  // 0 代表 OJ 不会测评该条目
  };
  Result example4 = {
      .type = NOTEN,
      .yaku = {},          // 全空代表 OJ 不会测评该条目
      .han = 0,           // 0 代表 OJ 不会测评该条目
      .fu = 0,            // 0 代表 OJ 不会测评该条目
      .point = {0, 0, 0},  // 全为零代表 OJ 不会测评该条目
      .machi = 0,         // 0 代表 OJ 不会测评该条目
      .shanten = 3,
  };

  if (status->bakaze == TON && status->jikaze == TON) {
    memcpy(result, &example0, sizeof(Result));
  }
  if (status->bakaze == TON && status->jikaze == NANN) {
    memcpy(result, &example1, sizeof(Result));
  }
  if (status->bakaze == NANN && status->jikaze == PEI) {
    memcpy(result, &example2, sizeof(Result));
  }
  if (status->bakaze == NANN && status->jikaze == SHAA) {
    memcpy(result, &example3, sizeof(Result));
  }
  if (status->bakaze == NANN && status->jikaze == TON) {
    memcpy(result, &example4, sizeof(Result));
  }
  return result;
}