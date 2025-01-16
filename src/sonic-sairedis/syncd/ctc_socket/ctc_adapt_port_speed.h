#ifndef _CTC_ADAPTPS_H
#define _CTC_ADAPTPS_H
#ifdef __cplusplus
extern "C" {
#endif

//STATUS_CODE
    
int ctc_adapt_port_speed_init(void);
int ctc_adapt_port_speed_uninit(void);
void ctc_aps_transinfo_current_speed_update(uint lchip, uint32_t gport, uint speed);
void ctc_aps_transinfo_data_get(uint lchip, uint32_t gport, void* data);


#ifdef __cplusplus
}
#endif

#endif
