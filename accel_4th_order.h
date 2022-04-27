/*
 * accel_4th_order.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "accel_4th_order".
 *
 * Model version              : 2.4
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Thu Feb 17 10:54:37 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_accel_4th_order_h_
#define RTW_HEADER_accel_4th_order_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "accel_4th_order_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_accel_4th_order_T {
  SL_Bus_accel_4th_order_geometry_msgs_Twist In1;/* '<S55>/In1' */
  SL_Bus_accel_4th_order_geometry_msgs_Twist BusAssignment;/* '<Root>/Bus Assignment' */
  real_T FilterCoefficient;            /* '<S41>/Filter Coefficient' */
  real_T Switch;                       /* '<S29>/Switch' */
  real_T Saturation2;                  /* '<Root>/Saturation2' */
  boolean_T AND3;                      /* '<S29>/AND3' */
  boolean_T Memory;                    /* '<S29>/Memory' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_accel_4th_order_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S3>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_i;/* '<S4>/SourceBlock' */
  boolean_T Memory_PreviousInput;      /* '<S29>/Memory' */
  boolean_T objisempty;                /* '<S4>/SourceBlock' */
  boolean_T objisempty_c;              /* '<S3>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_accel_4th_order_T {
  real_T TransferFcn3_CSTATE[5];       /* '<Root>/Transfer Fcn3' */
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
  real_T Filter_CSTATE;                /* '<S33>/Filter' */
};

/* State derivatives (default storage) */
struct XDot_accel_4th_order_T {
  real_T TransferFcn3_CSTATE[5];       /* '<Root>/Transfer Fcn3' */
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
  real_T Filter_CSTATE;                /* '<S33>/Filter' */
};

/* State disabled  */
struct XDis_accel_4th_order_T {
  boolean_T TransferFcn3_CSTATE[5];    /* '<Root>/Transfer Fcn3' */
  boolean_T Integrator_CSTATE;         /* '<S38>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S33>/Filter' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_accel_4th_order_T_ {
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S32>/Derivative Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S35>/Integral Gain'
                                        */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S33>/Filter'
                               */
  real_T PIDController2_InitialConditi_l;
                              /* Mask Parameter: PIDController2_InitialConditi_l
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by:
                               *   '<S45>/Saturation'
                               *   '<S31>/DeadZone'
                               */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S41>/Filter Coefficient'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by:
                               *   '<S45>/Saturation'
                               *   '<S31>/DeadZone'
                               */
  SL_Bus_accel_4th_order_geometry_msgs_Twist Constant_Value;/* Computed Parameter: Constant_Value
                                                             * Referenced by: '<S1>/Constant'
                                                             */
  SL_Bus_accel_4th_order_geometry_msgs_Twist Out1_Y0;/* Computed Parameter: Out1_Y0
                                                      * Referenced by: '<S55>/Out1'
                                                      */
  SL_Bus_accel_4th_order_geometry_msgs_Twist Constant_Value_a;/* Computed Parameter: Constant_Value_a
                                                               * Referenced by: '<S4>/Constant'
                                                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T TransferFcn3_A[5];            /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C[5];            /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S29>/ZeroGain'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1.5
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -3
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  boolean_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S29>/Memory'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_accel_4th_order_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_accel_4th_order_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[7];
  real_T odeF[3][7];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_accel_4th_order_T accel_4th_order_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_accel_4th_order_T accel_4th_order_B;

#ifdef __cplusplus

}
#endif

/* Continuous states (default storage) */
extern X_accel_4th_order_T accel_4th_order_X;

/* Block states (default storage) */
extern struct DW_accel_4th_order_T accel_4th_order_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void accel_4th_order_initialize(void);
  extern void accel_4th_order_step(void);
  extern void accel_4th_order_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_accel_4th_order_T *const accel_4th_order_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'accel_4th_order'
 * '<S1>'   : 'accel_4th_order/Blank Message'
 * '<S2>'   : 'accel_4th_order/PID Controller2'
 * '<S3>'   : 'accel_4th_order/Publish'
 * '<S4>'   : 'accel_4th_order/Subscribe'
 * '<S5>'   : 'accel_4th_order/PID Controller2/Anti-windup'
 * '<S6>'   : 'accel_4th_order/PID Controller2/D Gain'
 * '<S7>'   : 'accel_4th_order/PID Controller2/Filter'
 * '<S8>'   : 'accel_4th_order/PID Controller2/Filter ICs'
 * '<S9>'   : 'accel_4th_order/PID Controller2/I Gain'
 * '<S10>'  : 'accel_4th_order/PID Controller2/Ideal P Gain'
 * '<S11>'  : 'accel_4th_order/PID Controller2/Ideal P Gain Fdbk'
 * '<S12>'  : 'accel_4th_order/PID Controller2/Integrator'
 * '<S13>'  : 'accel_4th_order/PID Controller2/Integrator ICs'
 * '<S14>'  : 'accel_4th_order/PID Controller2/N Copy'
 * '<S15>'  : 'accel_4th_order/PID Controller2/N Gain'
 * '<S16>'  : 'accel_4th_order/PID Controller2/P Copy'
 * '<S17>'  : 'accel_4th_order/PID Controller2/Parallel P Gain'
 * '<S18>'  : 'accel_4th_order/PID Controller2/Reset Signal'
 * '<S19>'  : 'accel_4th_order/PID Controller2/Saturation'
 * '<S20>'  : 'accel_4th_order/PID Controller2/Saturation Fdbk'
 * '<S21>'  : 'accel_4th_order/PID Controller2/Sum'
 * '<S22>'  : 'accel_4th_order/PID Controller2/Sum Fdbk'
 * '<S23>'  : 'accel_4th_order/PID Controller2/Tracking Mode'
 * '<S24>'  : 'accel_4th_order/PID Controller2/Tracking Mode Sum'
 * '<S25>'  : 'accel_4th_order/PID Controller2/Tsamp - Integral'
 * '<S26>'  : 'accel_4th_order/PID Controller2/Tsamp - Ngain'
 * '<S27>'  : 'accel_4th_order/PID Controller2/postSat Signal'
 * '<S28>'  : 'accel_4th_order/PID Controller2/preSat Signal'
 * '<S29>'  : 'accel_4th_order/PID Controller2/Anti-windup/Cont. Clamping Parallel'
 * '<S30>'  : 'accel_4th_order/PID Controller2/Anti-windup/Cont. Clamping Parallel/Dead Zone'
 * '<S31>'  : 'accel_4th_order/PID Controller2/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
 * '<S32>'  : 'accel_4th_order/PID Controller2/D Gain/Internal Parameters'
 * '<S33>'  : 'accel_4th_order/PID Controller2/Filter/Cont. Filter'
 * '<S34>'  : 'accel_4th_order/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'accel_4th_order/PID Controller2/I Gain/Internal Parameters'
 * '<S36>'  : 'accel_4th_order/PID Controller2/Ideal P Gain/Passthrough'
 * '<S37>'  : 'accel_4th_order/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'accel_4th_order/PID Controller2/Integrator/Continuous'
 * '<S39>'  : 'accel_4th_order/PID Controller2/Integrator ICs/Internal IC'
 * '<S40>'  : 'accel_4th_order/PID Controller2/N Copy/Disabled'
 * '<S41>'  : 'accel_4th_order/PID Controller2/N Gain/Internal Parameters'
 * '<S42>'  : 'accel_4th_order/PID Controller2/P Copy/Disabled'
 * '<S43>'  : 'accel_4th_order/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'accel_4th_order/PID Controller2/Reset Signal/Disabled'
 * '<S45>'  : 'accel_4th_order/PID Controller2/Saturation/Enabled'
 * '<S46>'  : 'accel_4th_order/PID Controller2/Saturation Fdbk/Disabled'
 * '<S47>'  : 'accel_4th_order/PID Controller2/Sum/Sum_PID'
 * '<S48>'  : 'accel_4th_order/PID Controller2/Sum Fdbk/Disabled'
 * '<S49>'  : 'accel_4th_order/PID Controller2/Tracking Mode/Disabled'
 * '<S50>'  : 'accel_4th_order/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'accel_4th_order/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'accel_4th_order/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'accel_4th_order/PID Controller2/postSat Signal/Forward_Path'
 * '<S54>'  : 'accel_4th_order/PID Controller2/preSat Signal/Forward_Path'
 * '<S55>'  : 'accel_4th_order/Subscribe/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_accel_4th_order_h_ */
