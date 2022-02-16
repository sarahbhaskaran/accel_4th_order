/*
 * accel_4th_order_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "accel_4th_order".
 *
 * Model version              : 2.3
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Wed Feb 16 14:04:29 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "accel_4th_order.h"
#include "accel_4th_order_private.h"

/* Block parameters (default storage) */
P_accel_4th_order_T accel_4th_order_P = {
  /* Mask Parameter: PIDController2_D
   * Referenced by: '<S32>/Derivative Gain'
   */
  1.14032900506104,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S35>/Integral Gain'
   */
  0.134074922947779,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_l
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by:
   *   '<S45>/Saturation'
   *   '<S31>/DeadZone'
   */
  -3.0,

  /* Mask Parameter: PIDController2_N
   * Referenced by: '<S41>/Filter Coefficient'
   */
  2.31488315878784,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  1.0467641274631,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by:
   *   '<S45>/Saturation'
   *   '<S31>/DeadZone'
   */
  1.5,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    },                                 /* Linear */

    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    }                                  /* Angular */
  },

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S55>/Out1'
   */
  {
    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    },                                 /* Linear */

    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    }                                  /* Angular */
  },

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S4>/Constant'
   */
  {
    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    },                                 /* Linear */

    {
      0.0,                             /* X */
      0.0,                             /* Y */
      0.0                              /* Z */
    }                                  /* Angular */
  },

  /* Expression: 0
   * Referenced by: '<S29>/Constant1'
   */
  0.0,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  { -3.896, -94.32, -296.0, -666.0, -0.0 },

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  { 0.0, 0.0, 0.0, 0.0, 562.4 },

  /* Expression: 0
   * Referenced by: '<S29>/ZeroGain'
   */
  0.0,

  /* Expression: 1.5
   * Referenced by: '<Root>/Saturation2'
   */
  1.5,

  /* Expression: -3
   * Referenced by: '<Root>/Saturation2'
   */
  -3.0,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S29>/Memory'
   */
  false
};
