//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRPeer.h"
#include "BRSet.h"
#include "BRPeer.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "80.211.88.123:35888", "194.182.64.21:35888", "108.61.215.140:35888", "51.15.69.6:35888", "66.151.242.154:35888",
    "95.216.228.253:35888", "95.179.146.245:35888", NULL
};

static const char *BRTestNetDNSSeeds[] = {
    "testnet-seed.bitcoin.jonasschnelli.ch.", "seed.testnet.bitcoin.sprovoost.nl.",
    "testnet-seed.bluematt.me.", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
      {      0, uint256("000002ec3a1977ce2b036b1ab386eed53ea2f2ed4de1938c9c5fef918424023a"), 1529878570, 0x1e0ffff0 },
      {   1000, uint256("00000000002e8b26a88e86a6371d3e2fd61ecc79b4752afbd0e899fadc8ac624"), 1530479880, 0x1b512810 },
      {   2000, uint256("000000000013acbf3a2e3073426c66a05036680ed3d1307c0bd58ea9fb4462e0"), 1514904720, 0x1b76fe52 },
      {   5000, uint256("0000000000a08f12d8c4f28c38a39cbe96b6b9eff2ced17e1d72d5765b5d546d"), 1530732960, 0x1c00d83d },
      {  10000, uint256("00000000000ec12260b3d9bbdbce995b957048d41155c281d368101d498fca2b"), 1531048080, 0x1b776779 },
      {  25000, uint256("000000000063092b9dbf013565bc3c31774012410bf990bfe6fcbb09809607ea"), 1531991820, 0x1c00f4cf },
      {  50000, uint256("0000000000ff4450d4f295ce1388a834908bd997aae603ab52e3a17a0d6fce9d"), 1533565140, 0x1c018574 },
      {  75000, uint256("0000000001f7619df463d8d1128ac8f0c041a00a8390fda4db532e36f9cd7a0b"), 1535137620, 0x1c02216b },
      { 100000, uint256("000000000128ec84377aca0b6762018bce59c945357830a9cd58ec83cd085af1"), 1536710340, 0x1c01c594 },
      { 200000, uint256("0000000000c6cb04c640dc72e8ff59ec691ca3f9d252b983d9e025ba89271d42"), 1542997380, 0x1c01f931 },
      { 250000, uint256("00000000016ee8406edb199127a3b538ed0563581bea68fc3b3328f4642eaf0c"), 1546139280, 0x1c033815 },
      { 300000, uint256("00000000016626acf5d263e0d9c58c6a684298b80cb12af0be7f74e31e7ad26b"), 1549284660, 0x1c054706 },
      { 350000, uint256("000000000486f8d1f98fab9782002126ca50415d462098348c0fd740f5ef44f7"), 1552438920, 0x1c0648b8 },
      { 400000, uint256("00000000025d72b9ee13dafe0ac701a6b05f15aef22e591c5c6090dc8733dd54"), 1555588260, 0x1c07774c },
      { 450000, uint256("00000000026bc72cf1290bbfe160418477f7d4e03d75f83e78129ed79753776c"), 1558757460, 0x1c046a1a },
      { 500000, uint256("000000000db47096b590023d36bebe7ba2cb882728bd1850006d164ecdbf7cd1"), 1562012580, 0x1c0fd7df },
      { 750000, uint256("0000000006813c5da35196700ac7f95633b568562959ebe02668c46e7a685025"), 1577784420, 0x1c193987 },
      { 800000, uint256("000000000a02522c646acfe23fa2d6d638fee2807ad0ec38ec5a6708a1b58415"), 1580945940, 0x1c1e1d9b },
      { 815000, uint256("00000000096f40eb3eb8233ea50d2c278c22e0640e159fc167ead85cbc49fa95"), 1581895260, 0x1c431a11 },
 //   { 403200, uint256("000000000000000000c4272a5c68b4f55e5af734e88ceab09abf73e9ac3b6d01"), 1458292068, 0x1806a4c3 },
 //   { 423360, uint256("000000000000000001630546cde8482cc183708f076a5e4d6f51cd24518e8f85"), 1470163842, 0x18057228 },
  //  { 443520, uint256("00000000000000000345d0c7890b2c81ab5139c6e83400e5bed00d23a1f8d239"), 1481765313, 0x18038b85 },
//    { 463680, uint256("000000000000000000431a2f4619afe62357cd16589b638bb638f2992058d88e"), 1493259601, 0x18021b3e },
 //   { 483840, uint256("0000000000000000008e5d72027ef42ca050a0776b7184c96d0d4b300fa5da9e"), 1504704195, 0x1801310b },
 //   { 504000, uint256("0000000000000000006cd44d7a940c79f94c7c272d159ba19feb15891aa1ea54"), 1515827554, 0x177e578c },
//    { 524160, uint256("00000000000000000009d1e9bee76d334347060c6a2985d6cbc5c22e48f14ed2"), 1527168053, 0x17415a49 },
//    { 544320, uint256("0000000000000000000a5e9b5e4fbee51f3d53f31f40cd26b8e59ef86acb2ebd"), 1538639362, 0x1725c191 }
    //{ 564480,
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("000000000933ea01ad0ee984209779baaec3ced90fa3f408719526f8d77f4943"), 1296688602, 0x1d00ffff },
    {  100800, uint256("0000000000a33112f86f3f7b0aa590cb4949b84c2d9c673e9e303257b3be9000"), 1376543922, 0x1c00d907 },
    {  201600, uint256("0000000000376bb71314321c45de3015fe958543afcbada242a3b1b072498e38"), 1393813869, 0x1b602ac0 },
    {  302400, uint256("0000000000001c93ebe0a7c33426e8edb9755505537ef9303a023f80be29d32d"), 1413766239, 0x1a33605e },
    {  403200, uint256("0000000000ef8b05da54711e2106907737741ac0278d59f358303c71d500f3c4"), 1431821666, 0x1c02346c },
    {  504000, uint256("0000000000005d105473c916cd9d16334f017368afea6bcee71629e0fcf2f4f5"), 1436951946, 0x1b00ab86 },
    {  604800, uint256("00000000000008653c7e5c00c703c5a9d53b318837bb1b3586a3d060ce6fff2e"), 1447484641, 0x1a092a20 },
    {  705600, uint256("00000000004ee3bc2e2dd06c31f2d7a9c3e471ec0251924f59f222e5e9c37e12"), 1455728685, 0x1c0ffff0 },
    {  806400, uint256("0000000000000faf114ff29df6dbac969c6b4a3b407cd790d3a12742b50c2398"), 1462006183, 0x1a34e280 },
    {  907200, uint256("0000000000166938e6f172a21fe69fe335e33565539e74bf74eeb00d2022c226"), 1469705562, 0x1c00ffff },
    { 1008000, uint256("000000000000390aca616746a9456a0d64c1bd73661fd60a51b5bf1c92bae5a0"), 1476926743, 0x1a52ccc0 },
    { 1108800, uint256("00000000000288d9a219419d0607fb67cc324d4b6d2945ca81eaa5e739fab81e"), 1490751239, 0x1b09ecf0 },
    { 1209600, uint256("0000000000000026b4692a26f1651bec8e9d4905640bd8e56056c9a9c53badf8"), 1507353706, 0x1973e180 },
    { 1310400, uint256("0000000000013b434bbe5668293c92ef26df6d6d4843228e8958f6a3d8101709"), 1527063804, 0x1b0ffff0 },
    { 1411200, uint256("00000000000000008b3baea0c3de24b9333c169e1543874f4202397f5b8502cb"), 1535560970, 0x194ac105 }
    //{ 1512000, 
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet) {
    const BRMerkleBlock *previous, *b = NULL;
    uint32_t i;

    assert(block != NULL);
    assert(blockSet != NULL);

    // check if we hit a difficulty transition, and find previous transition block
    if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
        for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
            b = BRSetGet(blockSet, &b->prevBlock);
        }
    }

    previous = BRSetGet(blockSet, &block->prevBlock);
    return BRMerkleBlockVerifyDifficulty(block, previous, (b) ? b->timestamp : 0);
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet) {
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    35888,                  // standardPort
    0x6ab19cd5,            // magicNumber
    SERVICES_NODE_WITNESS, // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints)/sizeof(*BRMainNetCheckpoints)
};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    18333,                 // standardPort
    0x0709110b,            // magicNumber
    SERVICES_NODE_WITNESS, // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints)/sizeof(*BRTestNetCheckpoints)
};

#endif // BRChainParams_h
