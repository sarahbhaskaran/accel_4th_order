/*
 * accel_4th_order.cpp
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

#include "accel_4th_order.h"
#include "accel_4th_order_private.h"

/* Block signals (default storage) */
B_accel_4th_order_T accel_4th_order_B;

/* Continuous states */
X_accel_4th_order_T accel_4th_order_X;

/* Block states (default storage) */
DW_accel_4th_order_T accel_4th_order_DW;

/* Real-time model */
RT_MODEL_accel_4th_order_T accel_4th_order_M_ = RT_MODEL_accel_4th_order_T();
RT_MODEL_accel_4th_order_T *const accel_4th_order_M = &accel_4th_order_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  accel_4th_order_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  accel_4th_order_step();
  accel_4th_order_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  accel_4th_order_step();
  accel_4th_order_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void accel_4th_order_step(void)
{
  real_T rtb_SignPreIntegrator;
  real_T tmp;
  real_T tmp_0;
  if (rtmIsMajorTimeStep(accel_4th_order_M)) {
    /* set solver stop time */
    if (!(accel_4th_order_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&accel_4th_order_M->solverInfo,
                            ((accel_4th_order_M->Timing.clockTickH0 + 1) *
        accel_4th_order_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&accel_4th_order_M->solverInfo,
                            ((accel_4th_order_M->Timing.clockTick0 + 1) *
        accel_4th_order_M->Timing.stepSize0 +
        accel_4th_order_M->Timing.clockTickH0 *
        accel_4th_order_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(accel_4th_order_M)) {
    accel_4th_order_M->Timing.t[0] = rtsiGetT(&accel_4th_order_M->solverInfo);
  }

  /* Gain: '<S35>/Integral Gain' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn3'
   */
  accel_4th_order_B.Switch = 0.0;

  /* TransferFcn: '<Root>/Transfer Fcn3' */
  for (int_T ci = 0; ci < 5; ci++) {
    /* Gain: '<S35>/Integral Gain' incorporates:
     *  TransferFcn: '<Root>/Transfer Fcn3'
     */
    accel_4th_order_B.Switch += accel_4th_order_P.TransferFcn3_C[ci] *
      accel_4th_order_X.TransferFcn3_CSTATE[ci];
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Constant: '<S1>/Constant'
   */
  accel_4th_order_B.BusAssignment = accel_4th_order_P.Constant_Value;
  accel_4th_order_B.BusAssignment.Linear.X = accel_4th_order_B.Switch;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_accel_4th_order_33.publish(&accel_4th_order_B.BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
  if (rtmIsMajorTimeStep(accel_4th_order_M)) {
    boolean_T b_varargout_1;

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S4>/SourceBlock' incorporates:
     *  Inport: '<S55>/In1'
     */
    b_varargout_1 = Sub_accel_4th_order_27.getLatestMessage
      (&accel_4th_order_B.BusAssignment);

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S55>/Enable'
     */
    if (b_varargout_1) {
      accel_4th_order_B.In1 = accel_4th_order_B.BusAssignment;
    }

    /* End of MATLABSystem: '<S4>/SourceBlock' */
    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */
  }

  /* Gain: '<S35>/Integral Gain' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  accel_4th_order_B.Switch = accel_4th_order_B.In1.Linear.X -
    accel_4th_order_B.Switch;

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  accel_4th_order_B.FilterCoefficient = (accel_4th_order_P.PIDController2_D *
    accel_4th_order_B.Switch - accel_4th_order_X.Filter_CSTATE) *
    accel_4th_order_P.PIDController2_N;

  /* Saturate: '<S45>/Saturation' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   *  Integrator: '<S38>/Integrator'
   *  Sum: '<S47>/Sum'
   */
  accel_4th_order_B.Saturation2 = (accel_4th_order_P.PIDController2_P *
    accel_4th_order_B.Switch + accel_4th_order_X.Integrator_CSTATE) +
    accel_4th_order_B.FilterCoefficient;

  /* DeadZone: '<S31>/DeadZone' */
  if (accel_4th_order_B.Saturation2 >
      accel_4th_order_P.PIDController2_UpperSaturationL) {
    rtb_SignPreIntegrator = accel_4th_order_B.Saturation2 -
      accel_4th_order_P.PIDController2_UpperSaturationL;
  } else if (accel_4th_order_B.Saturation2 >=
             accel_4th_order_P.PIDController2_LowerSaturationL) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = accel_4th_order_B.Saturation2 -
      accel_4th_order_P.PIDController2_LowerSaturationL;
  }

  /* End of DeadZone: '<S31>/DeadZone' */

  /* Gain: '<S35>/Integral Gain' */
  accel_4th_order_B.Switch *= accel_4th_order_P.PIDController2_I;

  /* Signum: '<S29>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0) {
    /* DataTypeConversion: '<S29>/DataTypeConv1' */
    tmp = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    /* DataTypeConversion: '<S29>/DataTypeConv1' */
    tmp = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    /* DataTypeConversion: '<S29>/DataTypeConv1' */
    tmp = 0.0;
  } else {
    /* DataTypeConversion: '<S29>/DataTypeConv1' */
    tmp = (rtNaN);
  }

  /* End of Signum: '<S29>/SignPreSat' */

  /* DataTypeConversion: '<S29>/DataTypeConv1' */
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* Signum: '<S29>/SignPreIntegrator' */
  if (accel_4th_order_B.Switch < 0.0) {
    /* DataTypeConversion: '<S29>/DataTypeConv2' */
    tmp_0 = -1.0;
  } else if (accel_4th_order_B.Switch > 0.0) {
    /* DataTypeConversion: '<S29>/DataTypeConv2' */
    tmp_0 = 1.0;
  } else if (accel_4th_order_B.Switch == 0.0) {
    /* DataTypeConversion: '<S29>/DataTypeConv2' */
    tmp_0 = 0.0;
  } else {
    /* DataTypeConversion: '<S29>/DataTypeConv2' */
    tmp_0 = (rtNaN);
  }

  /* End of Signum: '<S29>/SignPreIntegrator' */

  /* DataTypeConversion: '<S29>/DataTypeConv2' */
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  /* Logic: '<S29>/AND3' incorporates:
   *  DataTypeConversion: '<S29>/DataTypeConv1'
   *  DataTypeConversion: '<S29>/DataTypeConv2'
   *  Gain: '<S29>/ZeroGain'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/NotEqual'
   */
  accel_4th_order_B.AND3 = ((accel_4th_order_P.ZeroGain_Gain *
    accel_4th_order_B.Saturation2 != rtb_SignPreIntegrator) && ((tmp < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp)))) == (tmp_0 < 0.0 ? static_cast<int32_T>(
    static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-tmp_0)))) :
    static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp_0))))));
  if (rtmIsMajorTimeStep(accel_4th_order_M)) {
    /* Memory: '<S29>/Memory' */
    accel_4th_order_B.Memory = accel_4th_order_DW.Memory_PreviousInput;
  }

  /* Switch: '<S29>/Switch' */
  if (accel_4th_order_B.Memory) {
    /* Gain: '<S35>/Integral Gain' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Switch: '<S29>/Switch'
     */
    accel_4th_order_B.Switch = accel_4th_order_P.Constant1_Value;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Saturate: '<S45>/Saturation' */
  if (accel_4th_order_B.Saturation2 >
      accel_4th_order_P.PIDController2_UpperSaturationL) {
    /* Saturate: '<S45>/Saturation' */
    accel_4th_order_B.Saturation2 =
      accel_4th_order_P.PIDController2_UpperSaturationL;
  } else if (accel_4th_order_B.Saturation2 <
             accel_4th_order_P.PIDController2_LowerSaturationL) {
    /* Saturate: '<S45>/Saturation' */
    accel_4th_order_B.Saturation2 =
      accel_4th_order_P.PIDController2_LowerSaturationL;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* Saturate: '<Root>/Saturation2' */
  if (accel_4th_order_B.Saturation2 > accel_4th_order_P.Saturation2_UpperSat) {
    /* Saturate: '<S45>/Saturation' incorporates:
     *  Saturate: '<Root>/Saturation2'
     */
    accel_4th_order_B.Saturation2 = accel_4th_order_P.Saturation2_UpperSat;
  } else if (accel_4th_order_B.Saturation2 <
             accel_4th_order_P.Saturation2_LowerSat) {
    /* Saturate: '<S45>/Saturation' incorporates:
     *  Saturate: '<Root>/Saturation2'
     */
    accel_4th_order_B.Saturation2 = accel_4th_order_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation2' */
  if (rtmIsMajorTimeStep(accel_4th_order_M)) {
    if (rtmIsMajorTimeStep(accel_4th_order_M)) {
      /* Update for Memory: '<S29>/Memory' */
      accel_4th_order_DW.Memory_PreviousInput = accel_4th_order_B.AND3;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(accel_4th_order_M)) {
    rt_ertODEUpdateContinuousStates(&accel_4th_order_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++accel_4th_order_M->Timing.clockTick0)) {
      ++accel_4th_order_M->Timing.clockTickH0;
    }

    accel_4th_order_M->Timing.t[0] = rtsiGetSolverStopTime
      (&accel_4th_order_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.05s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.05, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      accel_4th_order_M->Timing.clockTick1++;
      if (!accel_4th_order_M->Timing.clockTick1) {
        accel_4th_order_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void accel_4th_order_derivatives(void)
{
  XDot_accel_4th_order_T *_rtXdot;
  _rtXdot = ((XDot_accel_4th_order_T *) accel_4th_order_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  for (int_T is = 0; is < 5; is++) {
    _rtXdot->TransferFcn3_CSTATE[is] = 0.0;
    _rtXdot->TransferFcn3_CSTATE[0] += accel_4th_order_P.TransferFcn3_A[is] *
      accel_4th_order_X.TransferFcn3_CSTATE[is];
  }

  _rtXdot->TransferFcn3_CSTATE[1] += accel_4th_order_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[2] += accel_4th_order_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[3] += accel_4th_order_X.TransferFcn3_CSTATE[2];
  _rtXdot->TransferFcn3_CSTATE[4] += accel_4th_order_X.TransferFcn3_CSTATE[3];
  _rtXdot->TransferFcn3_CSTATE[0] += accel_4th_order_B.Saturation2;

  /* End of Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */

  /* Derivatives for Integrator: '<S38>/Integrator' */
  _rtXdot->Integrator_CSTATE = accel_4th_order_B.Switch;

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE = accel_4th_order_B.FilterCoefficient;
}

/* Model initialize function */
void accel_4th_order_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&accel_4th_order_M->solverInfo,
                          &accel_4th_order_M->Timing.simTimeStep);
    rtsiSetTPtr(&accel_4th_order_M->solverInfo, &rtmGetTPtr(accel_4th_order_M));
    rtsiSetStepSizePtr(&accel_4th_order_M->solverInfo,
                       &accel_4th_order_M->Timing.stepSize0);
    rtsiSetdXPtr(&accel_4th_order_M->solverInfo, &accel_4th_order_M->derivs);
    rtsiSetContStatesPtr(&accel_4th_order_M->solverInfo, (real_T **)
                         &accel_4th_order_M->contStates);
    rtsiSetNumContStatesPtr(&accel_4th_order_M->solverInfo,
      &accel_4th_order_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&accel_4th_order_M->solverInfo,
      &accel_4th_order_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&accel_4th_order_M->solverInfo,
      &accel_4th_order_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&accel_4th_order_M->solverInfo,
      &accel_4th_order_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&accel_4th_order_M->solverInfo, (&rtmGetErrorStatus
      (accel_4th_order_M)));
    rtsiSetRTModelPtr(&accel_4th_order_M->solverInfo, accel_4th_order_M);
  }

  rtsiSetSimTimeStep(&accel_4th_order_M->solverInfo, MAJOR_TIME_STEP);
  accel_4th_order_M->intgData.y = accel_4th_order_M->odeY;
  accel_4th_order_M->intgData.f[0] = accel_4th_order_M->odeF[0];
  accel_4th_order_M->intgData.f[1] = accel_4th_order_M->odeF[1];
  accel_4th_order_M->intgData.f[2] = accel_4th_order_M->odeF[2];
  accel_4th_order_M->contStates = ((X_accel_4th_order_T *) &accel_4th_order_X);
  rtsiSetSolverData(&accel_4th_order_M->solverInfo, static_cast<void *>
                    (&accel_4th_order_M->intgData));
  rtsiSetSolverName(&accel_4th_order_M->solverInfo,"ode3");
  rtmSetTPtr(accel_4th_order_M, &accel_4th_order_M->Timing.tArray[0]);
  accel_4th_order_M->Timing.stepSize0 = 0.05;

  /* block I/O */
  (void) memset((static_cast<void *>(&accel_4th_order_B)), 0,
                sizeof(B_accel_4th_order_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&accel_4th_order_X), 0,
                  sizeof(X_accel_4th_order_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&accel_4th_order_DW), 0,
                sizeof(DW_accel_4th_order_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[8];
    char_T b_zeroDelimTopic[6];
    static const char_T tmp[5] = { 'v', '_', 'a', 'c', 't' };

    static const char_T tmp_0[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    accel_4th_order_DW.obj.matlabCodegenIsDeleted = false;
    accel_4th_order_DW.objisempty_c = true;
    accel_4th_order_DW.obj.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Pub_accel_4th_order_33.createPublisher(&b_zeroDelimTopic[0], 1);
    accel_4th_order_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    accel_4th_order_DW.obj_i.matlabCodegenIsDeleted = false;
    accel_4th_order_DW.objisempty = true;
    accel_4th_order_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[7] = '\x00';
    Sub_accel_4th_order_27.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    accel_4th_order_DW.obj_i.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  for (int_T is = 0; is < 5; is++) {
    accel_4th_order_X.TransferFcn3_CSTATE[is] = 0.0;
  }

  /* End of InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */

  /* InitializeConditions for Integrator: '<S38>/Integrator' */
  accel_4th_order_X.Integrator_CSTATE =
    accel_4th_order_P.PIDController2_InitialConditi_l;

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  accel_4th_order_X.Filter_CSTATE =
    accel_4th_order_P.PIDController2_InitialCondition;

  /* InitializeConditions for Memory: '<S29>/Memory' */
  accel_4th_order_DW.Memory_PreviousInput =
    accel_4th_order_P.Memory_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S55>/Out1' incorporates:
   *  Inport: '<S55>/In1'
   */
  accel_4th_order_B.In1 = accel_4th_order_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */
}

/* Model terminate function */
void accel_4th_order_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!accel_4th_order_DW.obj.matlabCodegenIsDeleted) {
    accel_4th_order_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!accel_4th_order_DW.obj_i.matlabCodegenIsDeleted) {
    accel_4th_order_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */
}
