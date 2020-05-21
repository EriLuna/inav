/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControllerTest.c
 *
 * Code generated for Simulink model 'ControllerTest'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 15 12:05:19 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControllerTest.h"
#include "ControllerTest_private.h"

/* Block signals (default storage) */
B_ControllerTest_T ControllerTest_B;

/* Continuous states */
X_ControllerTest_T ControllerTest_X;

/* Block states (default storage) */
DW_ControllerTest_T ControllerTest_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ControllerTest_T ControllerTest_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ControllerTest_T ControllerTest_Y;

/* Real-time model */
RT_MODEL_ControllerTest_T ControllerTest_M_;
RT_MODEL_ControllerTest_T *const ControllerTest_M = &ControllerTest_M_;

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
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ControllerTest_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ControllerTest_step();
  ControllerTest_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ControllerTest_step();
  ControllerTest_derivatives();

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
void ControllerTest_step(void)
{
  real_T rtb_Subtract1;
  if (rtmIsMajorTimeStep(ControllerTest_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ControllerTest_M->solverInfo,
                          ((ControllerTest_M->Timing.clockTick0+1)*
      ControllerTest_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ControllerTest_M)) {
    ControllerTest_M->Timing.t[0] = rtsiGetT(&ControllerTest_M->solverInfo);
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Inport: '<Root>/AltitudeRef'
   *  Inport: '<Root>/NegativeStep'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum1'
   *  TransferFcn: '<Root>/Plant'
   */
  ControllerTest_B.Subtract = (ControllerTest_U.AltitudeRef +
    ControllerTest_U.NegativeStep) - ((0.0 * ControllerTest_X.Plant_CSTATE[0] +
    -400000.0 * ControllerTest_X.Plant_CSTATE[1]) + ControllerTest_U.AltitudeRef);

  /* Sum: '<Root>/Subtract1' incorporates:
   *  Inport: '<Root>/ThetaAngle'
   *  ZeroPole: '<Root>/Altitude Lead Controller'
   */
  rtb_Subtract1 = (-0.63110383296 *
                   ControllerTest_X.AltitudeLeadController_CSTATE + 0.033728 *
                   ControllerTest_B.Subtract) - ControllerTest_U.ThetaAngle;

  /* Gain: '<S67>/Filter Coefficient' incorporates:
   *  Gain: '<S34>/Derivative Gain'
   *  Integrator: '<S35>/Filter'
   *  Sum: '<S35>/SumD'
   */
  ControllerTest_B.FilterCoefficient = (2.0 * rtb_Subtract1 -
    ControllerTest_X.Filter_CSTATE) * 100.0;

  /* Sum: '<S87>/Sum' incorporates:
   *  Gain: '<S74>/Proportional Gain'
   *  Integrator: '<S55>/Integrator'
   */
  ControllerTest_B.Sum = (-300.0 * rtb_Subtract1 +
    ControllerTest_X.Integrator_CSTATE) + ControllerTest_B.FilterCoefficient;
  if (rtmIsMajorTimeStep(ControllerTest_M)) {
    /* Sum: '<S1>/Diff' incorporates:
     *  UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    ControllerTest_Y.Elev_cmd = ControllerTest_B.Sum -
      ControllerTest_DW.UD_DSTATE;

    /* Saturate: '<Root>/Saturation' */
    if (ControllerTest_Y.Elev_cmd > 0.35) {
      /* Sum: '<S1>/Diff' incorporates:
       *  Outport: '<Root>/Elev_cmd'
       *
       * Block description for '<S1>/Diff':
       *
       *  Add in CPU
       */
      ControllerTest_Y.Elev_cmd = 0.35;
    } else {
      if (ControllerTest_Y.Elev_cmd < -0.35) {
        /* Sum: '<S1>/Diff' incorporates:
         *  Outport: '<Root>/Elev_cmd'
         *
         * Block description for '<S1>/Diff':
         *
         *  Add in CPU
         */
        ControllerTest_Y.Elev_cmd = -0.35;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */
  }

  /* Gain: '<S47>/Integral Gain' */
  ControllerTest_B.IntegralGain = -15000.0 * rtb_Subtract1;

  /* Outport: '<Root>/AltError' */
  ControllerTest_Y.AltError = ControllerTest_B.Subtract;
  if (rtmIsMajorTimeStep(ControllerTest_M)) {
    if (rtmIsMajorTimeStep(ControllerTest_M)) {
      /* Update for UnitDelay: '<S1>/UD'
       *
       * Block description for '<S1>/UD':
       *
       *  Store in Global RAM
       */
      ControllerTest_DW.UD_DSTATE = ControllerTest_B.Sum;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ControllerTest_M)) {
    rt_ertODEUpdateContinuousStates(&ControllerTest_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ControllerTest_M->Timing.clockTick0;
    ControllerTest_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ControllerTest_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      ControllerTest_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ControllerTest_derivatives(void)
{
  XDot_ControllerTest_T *_rtXdot;
  _rtXdot = ((XDot_ControllerTest_T *) ControllerTest_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Plant' incorporates:
   *  Outport: '<Root>/Elev_cmd'
   */
  _rtXdot->Plant_CSTATE[0] = 0.0;
  _rtXdot->Plant_CSTATE[0] += -1200.0 * ControllerTest_X.Plant_CSTATE[0];
  _rtXdot->Plant_CSTATE[1] = 0.0;
  _rtXdot->Plant_CSTATE[0] += -2400.0 * ControllerTest_X.Plant_CSTATE[1];
  _rtXdot->Plant_CSTATE[1] += ControllerTest_X.Plant_CSTATE[0];
  _rtXdot->Plant_CSTATE[0] += ControllerTest_Y.Elev_cmd;

  /* Derivatives for ZeroPole: '<Root>/Altitude Lead Controller' */
  _rtXdot->AltitudeLeadController_CSTATE = 0.0;
  _rtXdot->AltitudeLeadController_CSTATE += -25.7546 *
    ControllerTest_X.AltitudeLeadController_CSTATE;
  _rtXdot->AltitudeLeadController_CSTATE += ControllerTest_B.Subtract;

  /* Derivatives for Integrator: '<S55>/Integrator' */
  _rtXdot->Integrator_CSTATE = ControllerTest_B.IntegralGain;

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE = ControllerTest_B.FilterCoefficient;
}

/* Model initialize function */
void ControllerTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ControllerTest_M, 0,
                sizeof(RT_MODEL_ControllerTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControllerTest_M->solverInfo,
                          &ControllerTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControllerTest_M->solverInfo, &rtmGetTPtr(ControllerTest_M));
    rtsiSetStepSizePtr(&ControllerTest_M->solverInfo,
                       &ControllerTest_M->Timing.stepSize0);
    rtsiSetdXPtr(&ControllerTest_M->solverInfo, &ControllerTest_M->derivs);
    rtsiSetContStatesPtr(&ControllerTest_M->solverInfo, (real_T **)
                         &ControllerTest_M->contStates);
    rtsiSetNumContStatesPtr(&ControllerTest_M->solverInfo,
      &ControllerTest_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ControllerTest_M->solverInfo,
      &ControllerTest_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ControllerTest_M->solverInfo,
      &ControllerTest_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ControllerTest_M->solverInfo,
      &ControllerTest_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ControllerTest_M->solverInfo, (&rtmGetErrorStatus
      (ControllerTest_M)));
    rtsiSetRTModelPtr(&ControllerTest_M->solverInfo, ControllerTest_M);
  }

  rtsiSetSimTimeStep(&ControllerTest_M->solverInfo, MAJOR_TIME_STEP);
  ControllerTest_M->intgData.y = ControllerTest_M->odeY;
  ControllerTest_M->intgData.f[0] = ControllerTest_M->odeF[0];
  ControllerTest_M->intgData.f[1] = ControllerTest_M->odeF[1];
  ControllerTest_M->intgData.f[2] = ControllerTest_M->odeF[2];
  ControllerTest_M->contStates = ((X_ControllerTest_T *) &ControllerTest_X);
  rtsiSetSolverData(&ControllerTest_M->solverInfo, (void *)
                    &ControllerTest_M->intgData);
  rtsiSetSolverName(&ControllerTest_M->solverInfo,"ode3");
  rtmSetTPtr(ControllerTest_M, &ControllerTest_M->Timing.tArray[0]);
  ControllerTest_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &ControllerTest_B), 0,
                sizeof(B_ControllerTest_T));

  /* states (continuous) */
  {
    (void) memset((void *)&ControllerTest_X, 0,
                  sizeof(X_ControllerTest_T));
  }

  /* states (dwork) */
  (void) memset((void *)&ControllerTest_DW, 0,
                sizeof(DW_ControllerTest_T));

  /* external inputs */
  (void)memset(&ControllerTest_U, 0, sizeof(ExtU_ControllerTest_T));

  /* external outputs */
  (void) memset((void *)&ControllerTest_Y, 0,
                sizeof(ExtY_ControllerTest_T));

  /* InitializeConditions for TransferFcn: '<Root>/Plant' */
  ControllerTest_X.Plant_CSTATE[0] = 0.0;
  ControllerTest_X.Plant_CSTATE[1] = 0.0;

  /* InitializeConditions for ZeroPole: '<Root>/Altitude Lead Controller' */
  ControllerTest_X.AltitudeLeadController_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S55>/Integrator' */
  ControllerTest_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  ControllerTest_X.Filter_CSTATE = 0.0;
}

/* Model terminate function */
void ControllerTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
