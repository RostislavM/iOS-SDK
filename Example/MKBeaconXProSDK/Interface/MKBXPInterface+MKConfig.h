//
//  MKBXPInterface+MKConfig.h
//  BeaconXPlus
//
//  Created by aa on 2019/5/25.
//  Copyright © 2019 MK. All rights reserved.
//

#import "MKBXPInterface.h"
#import "MKBXPEnumeration.h"
#import "MKBXPProtocols.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKBXPInterface (MKConfig)

/**
 Modifying connection password.Only if the device’s LockState is in UNLOCKED state, the password can be modified.
 
 @param newPassword New password, 16 characters
 @param originalPassword Old password, 16 characters
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPNewPassword:(NSString *)newPassword
         originalPassword:(NSString *)originalPassword
                 sucBlock:(void (^)(id returnData))sucBlock
              failedBlock:(void (^)(NSError *error))failedBlock;

/**
 Resetting to factory state (RESET).NOTE:When resetting the device, the connection password will not be restored which shall remain set to its current value.

 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)BXPFactoryDataResetWithSucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;
/**
 设置lockState

 @param lockState MKBXPLockState
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPLockState:(MKBXPLockState)lockState
               sucBlock:(void (^)(id returnData))sucBlock
            failedBlock:(void (^)(NSError *error))failedBlock;

/**
 Setting device power off

 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPPowerOffWithSucBlockWithSucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Setting device’s connection status.
 NOTE: Be careful to set device’s connection statue .Once the device is set to not connectable, it may not be connected, and other parameters cannot be configured.
 
 @param connectEnable YES：Connectable，NO：Not Connectable
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPConnectStatus:(BOOL)connectEnable
                   sucBlock:(void (^)(id returnData))sucBlock
                failedBlock:(void (^)(NSError *error))failedBlock;
/**
 MokoBeaconX provides up to 6 SLOTs for users to configure advertisement frame. Before configering the SLOT’s parameter， you should switch the SLOT to target SLOT fristly; otherwise the configuration is only for the currently active SLOT.

 @param slotNo Target SLOT number to switch to
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPActiveSlot:(bxpActiveSlotNo)slotNo
                sucBlock:(void (^)(id returnData))sucBlock
             failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Setting Advertised Tx Power(RSSI@0m, only for eddystone frame).Advertised Tx Power is different for each SLOT. Before setting the target SLOT’s Advertised Tx Power, you should switch the SLOT to target SLOT(Please refer to ，setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the Advertised Tx Power set is only for the currently active SLOT.
 
 @param advTxPower Advertised Tx Power, range from -100dBm to +20dBm
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPAdvTxPower:(NSInteger)advTxPower
                sucBlock:(void (^)(id returnData))sucBlock
             failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Setting Radio Tx Power.Radio Tx Power is different for each SLOT. Before setting the target SLOT’s Radio Tx Power, you should switch the SLOT to target SLOT(Please refer to ，setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the Radio Tx Power set is only for the currently active SLOT.

 @param power power
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPRadioTxPower:(slotRadioTxPower )power
                  sucBlock:(void (^)(id returnData))sucBlock
               failedBlock:(void (^)(NSError *error))failedBlock;
/**
 设置当前通道的广播间隔

 @param interval 广播间隔，单位100ms，范围:1~100
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPAdvInterval:(NSInteger)interval
                 sucBlock:(void (^)(id returnData))sucBlock
              failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Configuring currently active SLOT as TLM.To configure the target SLOT type as TLM, you should switch the SLOT to target SLOT(Please refer to setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the currently active SLOT will configured as TLM.
 
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTLMAdvDataWithSucBlock:(void (^)(id returnData))sucBlock
                         failedBlock:(void (^)(NSError *error))failedBlock;
/**
 configuring currently active SLOT as UID.To configure the target SLOT type as UID, you should switch the SLOT to target SLOT(Please refer to setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the currently active SLOT will configured as UID.
 
 @param nameSpace NameSpace, 20 characters
 @param instanceID Instance，12 characters
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPUIDAdvDataWithNameSpace:(NSString *)nameSpace
                           instanceID:(NSString *)instanceID
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Configuring currently active SLOT as URL.To configure the target SLOT type as URL, you should switch the SLOT to target SLOT(Please refer to setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the currently active SLOT will configured as URL.
 
 @param urlHeader URL Scheme Prefix.
 @param urlContent Encoded URL. If the URL contains HTTP URL encoding, the length of the left datas should be 16bytes at most. If the URL doesn’t contain HTTP URL encoding, the full length of Encoded URL should be 2-17bytes.
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPURLAdvData:(urlHeaderType )urlHeader
              urlContent:(NSString *)urlContent
                sucBlock:(void (^)(id returnData))sucBlock
             failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Configuring currently active SLOT as iBeacon.To configure the target SLOT type as iBeacon, you should switch the SLOT to target SLOT(Please refer to setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the currently active SLOT will configured as iBeacon.
 
 @param major major,0~65535
 @param minor minor,0~65535
 @param uuid uuid
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPiBeaconAdvDataWithMajor:(NSInteger)major
                                minor:(NSInteger)minor
                                 uuid:(NSString *)uuid
                             sucBlock:(void (^)(id returnData))sucBlock
                          failedBlock:(void (^)(NSError *error))failedBlock;
/**
 Configuring currently active SLOT as NO DATA.To configure the target SLOT type as NO DATA, you should switch the SLOT to target SLOT(Please refer to setEddystoneActiveSlot:sucBlock:failedBlock:); otherwise the currently active SLOT will configured as NO DATA.
 
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPNODATAAdvDataWithSucBlock:(void (^)(id returnData))sucBlock
                            failedBlock:(void (^)(NSError *error))failedBlock;

/**
 Setting Device Name

 @param deviceName deviceName，1~20 characters
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPDeviceInfoAdvDataWithDeviceName:(NSString *)deviceName
                                     sucBlock:(void (^)(id returnData))sucBlock
                                  failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置当前通道为三轴传感器

 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPThreeAxisAdvDataWithSucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置当前通道为温湿度数据通道

 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPHTAdvDataWithSucBlock:(void (^)(id returnData))sucBlock
                        failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置3轴传感器采样率、重力加速度参考值、灵敏度

 @param dataRate 采样率
 @param acceleration 重力加速度参考值
 @param sensitivity 设备发生移动的灵敏度，数值越大，越迟钝。7~255
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPThreeAxisDataParams:(threeAxisDataRate)dataRate
                     acceleration:(threeAxisDataAG)acceleration
                      sensitivity:(NSInteger)sensitivity
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置设备的当前时间

 @param protocol time
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPDeviceTime:(id <MKBXPDeviceTimeProtocol>)protocol
                sucBlock:(void (^)(id returnData))sucBlock
             failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置传感器温湿度储存数据条件

 @param protocol protocol
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPHTStorageConditions:(id <MKBXPHTStorageConditionsProtocol>)protocol
                         sucBlock:(void (^)(id returnData))sucBlock
                      failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置温湿度采样率

 @param rate 采样率，单位为S，即多少秒采样一次温湿度数据，1s~65535s
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPHTSamplingRate:(NSInteger)rate
                    sucBlock:(void (^)(id returnData))sucBlock
                 failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置当前活跃通道无触发条件

 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTriggerConditionsNoneWithSuccessBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置当前活跃通道温度触发条件

 @param above YES:当温度高于temperature时触发,NO:当温度低于temperature时触发
 @param temperature 触发的温度条件,-20~90
 @param start YES:开始广播,NO:停止广播
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTriggerConditionsWithTemperature:(BOOL)above
                                   temperature:(NSInteger)temperature
                              startAdvertising:(BOOL)start
                                      sucBlock:(void (^)(id returnData))sucBlock
                                   failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置当前活跃通道湿度触发条件

 @param above YES:当温度高于humidity时触发,NO:当温度低于humidity时触发
 @param humidity 触发的湿度条件,0~100
 @param start YES:开始广播,NO:停止广播
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTriggerConditionsWithHudimity:(BOOL)above
                                   humidity:(NSInteger)humidity
                           startAdvertising:(BOOL)start
                                   sucBlock:(void (^)(id returnData))sucBlock
                                failedBlock:(void (^)(NSError *error))failedBlock;

/**
 设置当前活跃通道双击触发条件

 @param time 持续时间，单位s,0~65535
 @param start YES:开始广播,NO:停止广播
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTriggerConditionsWithDoubleTap:(NSInteger)time
                                       start:(BOOL)start
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;
/**
 设置当前活跃通道三击触发条件
 
 @param time 持续时间，单位s,0~65535
 @param start YES:开始广播,NO:停止广播
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTriggerConditionsWithTripleTap:(NSInteger)time
                                       start:(BOOL)start
                                    sucBlock:(void (^)(id returnData))sucBlock
                                 failedBlock:(void (^)(NSError *error))failedBlock;
/**
 设置当前活跃通道移动触发条件
 
 @param time 持续时间，单位s,0~65535
 @param start YES:开始广播,NO:停止广播
 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)setBXPTriggerConditionsWithMoves:(NSInteger)time
                                   start:(BOOL)start
                                sucBlock:(void (^)(id returnData))sucBlock
                             failedBlock:(void (^)(NSError *error))failedBlock;

/**
 删除设备存储的温湿度数据

 @param sucBlock success callback
 @param failedBlock failed callback
 */
+ (void)deleteBXPRecordHTDatasWithSucBlock:(void (^)(id returnData))sucBlock
                               failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
