#ifndef _CTC_TRANSCEIVER_H
#define _CTC_TRANSCEIVER_H


#include "api/include/ctcs_api.h"

#define  CTC_TRANS_SUCCESS            0
#define  CTC_TRANS_ERR_INIT           -100
#define  CTC_TRANS_ERR_IO             -101
#define  CTC_TRANS_ERR_INFO           -102

#define  LAN_MAX                    4
#define TRANS_I2C_ADDR1     0x50
#define TRANS_I2C_ADDR2     0x51
#define TRANS_E2P_HADINFO  1
#define TRANS_E2P_NOINFO   0
#define TRANS_E2P_INFO_LEN_128  128
#define TRANS_E2P_INFO_LEN_256  256
#define TRANS_E2P_INFO_LEN_512  512

#define TRANS_APS_DEBUG    0

enum ctc_aps_optoe_type
{
    TRANS_TYPE_SFP = 0,
    TRANS_TYPE_QSFP = 1,
};
typedef enum ctc_aps_optoe_type ctc_aps_optoe_type_e;


enum ctc_aps_port_speed_auto
{
    CTC_APS_PORT_SPEED_AUTO_EN = 0,
    CTC_APS_PORT_SPEED_AUTO_DIS = 1,
};
typedef enum ctc_aps_port_speed_auto ctc_aps_port_speed_auto_e;


typedef struct ctc_port_transio
{
    uint8 prs;
    uint8 los;
    uint8 dis;
}ctc_port_transio_t;

typedef struct ctc_port_trans_data_prs
{
    uint8 stats;
    ctc_aps_optoe_type_e type;
    uint8 e2p_data[TRANS_E2P_INFO_LEN_512];
}ctc_port_trans_data_prs_t;

typedef struct ctc_port_speed_stats
{
    ctc_aps_port_speed_auto_e conf_auto;
    ctc_port_speed_t conf_speed;
}ctc_port_speed_stats;


typedef struct ctc_trans_e2pinfo
{
    uint8  serial_number[32];
    uint8  part_number[32];
    uint8  vendor_name[32];
    uint8  optoe_speed;
    uint16 wavelength;
    int16  temp;    
    uint32 rx_power_uw[LAN_MAX];
    uint32 tx_power_uw[LAN_MAX];
}ctc_trans_e2pinfo_t;

typedef struct ctc_port_transinfo
{
    uint8 uid;    
    uint8 e2pupdate_flag;
    uint8 e2p_info_data[TRANS_E2P_INFO_LEN_512];
    ctc_port_transio_t io_stat;
    ctc_trans_e2pinfo_t e2pinfo;
    ctc_port_if_type_t match_iftype;
    ctc_port_speed_stats current_speed;
}ctc_port_transinfo_t;


int ctc_aps_transio_update(ctc_port_trans_cfg_t* port_trans_cfg,ctc_port_transinfo_t port_trans_info[][CTC_DATAPATH_SERDES_NUM]);
int ctc_aps_transinfo_update(ctc_port_trans_cfg_t* port_trans_cfg,ctc_port_transinfo_t port_trans_info[][CTC_DATAPATH_SERDES_NUM]);

#endif
