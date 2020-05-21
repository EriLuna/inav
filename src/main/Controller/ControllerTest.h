/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControllerTest.h
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

#ifndef RTW_HEADER_ControllerTest_h_
#define RTW_HEADER_ControllerTest_h_
#include <string.h>
#ifndef ControllerTest_COMMON_INCLUDES_
# define ControllerTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ControllerTest_COMMON_INCLUDES_ */

#include "ControllerTest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T FilterCoefficient;            /* '<S67>/Filter Coefficient' */
  real_T Sum;                          /* '<S87>/Sum' */
  real_T IntegralGain;                 /* '<S47>/Integral Gain' */
} B_ControllerTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
} DW_ControllerTest_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Plant_CSTATE[2];              /* '<Root>/Plant' */
  real_T AltitudeLeadController_CSTATE;/* '<Root>/Altitude Lead Controller' */
  real_T Integrator_CSTATE;            /* '<S55>/Integrator' */
  real_T Filter_CSTATE;                /* '<S35>/Filter' */
} X_ControllerTest_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Plant_CSTATE[2];              /* '<Root>/Plant' */
  real_T AltitudeLeadController_CSTATE;/* '<Root>/Altitude Lead Controller' */
  real_T Integrator_CSTATE;            /* '<S55>/Integrator' */
  real_T Filter_CSTATE;                /* '<S35>/Filter' */
} XDot_ControllerTest_T;

/* State disabled  */
typedef struct {
  boolean_T Plant_CSTATE[2];           /* '<Root>/Plant' */
  boolean_T AltitudeLeadController_CSTATE;/* '<Root>/Altitude Lead Controller' */
  boolean_T Integrator_CSTATE;         /* '<S55>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S35>/Filter' */
} XDis_ControllerTest_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ThetaAngle;                   /* '<Root>/ThetaAngle' */
  real_T AltitudeRef;                  /* '<Root>/AltitudeRef' */
  real_T NegativeStep;                 /* '<Root>/NegativeStep' */
} ExtU_ControllerTest_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Elev_cmd;                     /* '<Root>/Elev_cmd' */
  real_T AltError;                     /* '<Root>/AltError' */
} ExtY_ControllerTest_T;

/* Real-time Model Data Structure */
struct tag_RTM_ControllerTest_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ControllerTest_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
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
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_ControllerTest_T ControllerTest_B;

/* Continuous states (default storage) */
extern X_ControllerTest_T ControllerTest_X;

/* Block states (default storage) */
extern DW_ControllerTest_T ControllerTest_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ControllerTest_T ControllerTest_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ControllerTest_T ControllerTest_Y;

/* Model entry point functions */
extern void ControllerTest_initialize(void);
extern void ControllerTest_step(void);
extern void ControllerTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ControllerTest_T *const ControllerTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/AltDemand ' : Unused code path elimination
 * Block '<Root>/Altitude_Feedback' : Unused code path elimination
 * Block '<Root>/Altitude_Measured' : Unused code path elimination
 * Block '<Root>/Altitude_Measured1' : Unused code path elimination
 * Block '<Root>/Altitude_Measured2' : Unused code path elimination
 * Block '<Root>/Altitude_Measured3' : Unused code path elimination
 * Block '<Root>/Altitude_Reference' : Unused code path elimination
 * Block '<Root>/Altitude_error' : Unused code path elimination
 * Block '<Root>/Elev_Dem ' : Unused code path elimination
 * Block '<Root>/Negative_Altitude_Step' : Unused code path elimination
 * Block '<Root>/PID_Out' : Unused code path elimination
 * Block '<Root>/Positive_Altitude_Step' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Steady_State' : Unused code path elimination
 * Block '<Root>/Step_Selection' : Unused code path elimination
 * Block '<Root>/Theta_Angle_Selector' : Unused code path elimination
 * Block '<Root>/Theta_Angle_Selector1' : Unused code path elimination
 * Block '<Root>/Theta_Angle_Selector2' : Unused code path elimination
 * Block '<Root>/Theta_Max' : Unused code path elimination
 * Block '<Root>/Theta_Min' : Unused code path elimination
 * Block '<Root>/Theta_Selection' : Unused code path elimination
 * Block '<Root>/Theta_Zero' : Unused code path elimination
 */

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
 * '<Root>' : 'ControllerTest'
 * '<S1>'   : 'ControllerTest/Difference Filter'
 * '<S2>'   : 'ControllerTest/PID Controller'
 * '<S3>'   : 'ControllerTest/PID Controller/Anti-windup'
 * '<S4>'   : 'ControllerTest/PID Controller/D Gain'
 * '<S5>'   : 'ControllerTest/PID Controller/Filter'
 * '<S6>'   : 'ControllerTest/PID Controller/Filter ICs'
 * '<S7>'   : 'ControllerTest/PID Controller/I Gain'
 * '<S8>'   : 'ControllerTest/PID Controller/Ideal P Gain'
 * '<S9>'   : 'ControllerTest/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'ControllerTest/PID Controller/Integrator'
 * '<S11>'  : 'ControllerTest/PID Controller/Integrator ICs'
 * '<S12>'  : 'ControllerTest/PID Controller/N Copy'
 * '<S13>'  : 'ControllerTest/PID Controller/N Gain'
 * '<S14>'  : 'ControllerTest/PID Controller/P Copy'
 * '<S15>'  : 'ControllerTest/PID Controller/Parallel P Gain'
 * '<S16>'  : 'ControllerTest/PID Controller/Reset Signal'
 * '<S17>'  : 'ControllerTest/PID Controller/Saturation'
 * '<S18>'  : 'ControllerTest/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'ControllerTest/PID Controller/Sum'
 * '<S20>'  : 'ControllerTest/PID Controller/Sum Fdbk'
 * '<S21>'  : 'ControllerTest/PID Controller/Tracking Mode'
 * '<S22>'  : 'ControllerTest/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'ControllerTest/PID Controller/postSat Signal'
 * '<S24>'  : 'ControllerTest/PID Controller/preSat Signal'
 * '<S25>'  : 'ControllerTest/PID Controller/Anti-windup/Back Calculation'
 * '<S26>'  : 'ControllerTest/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S27>'  : 'ControllerTest/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S28>'  : 'ControllerTest/PID Controller/Anti-windup/Disabled'
 * '<S29>'  : 'ControllerTest/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S30>'  : 'ControllerTest/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S31>'  : 'ControllerTest/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'ControllerTest/PID Controller/D Gain/Disabled'
 * '<S33>'  : 'ControllerTest/PID Controller/D Gain/External Parameters'
 * '<S34>'  : 'ControllerTest/PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'ControllerTest/PID Controller/Filter/Cont. Filter'
 * '<S36>'  : 'ControllerTest/PID Controller/Filter/Differentiator'
 * '<S37>'  : 'ControllerTest/PID Controller/Filter/Disabled'
 * '<S38>'  : 'ControllerTest/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S39>'  : 'ControllerTest/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'ControllerTest/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S41>'  : 'ControllerTest/PID Controller/Filter ICs/Disabled'
 * '<S42>'  : 'ControllerTest/PID Controller/Filter ICs/External IC'
 * '<S43>'  : 'ControllerTest/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S44>'  : 'ControllerTest/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S45>'  : 'ControllerTest/PID Controller/I Gain/Disabled'
 * '<S46>'  : 'ControllerTest/PID Controller/I Gain/External Parameters'
 * '<S47>'  : 'ControllerTest/PID Controller/I Gain/Internal Parameters'
 * '<S48>'  : 'ControllerTest/PID Controller/Ideal P Gain/External Parameters'
 * '<S49>'  : 'ControllerTest/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S50>'  : 'ControllerTest/PID Controller/Ideal P Gain/Passthrough'
 * '<S51>'  : 'ControllerTest/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S52>'  : 'ControllerTest/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S53>'  : 'ControllerTest/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S54>'  : 'ControllerTest/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S55>'  : 'ControllerTest/PID Controller/Integrator/Continuous'
 * '<S56>'  : 'ControllerTest/PID Controller/Integrator/Disabled'
 * '<S57>'  : 'ControllerTest/PID Controller/Integrator/Discrete'
 * '<S58>'  : 'ControllerTest/PID Controller/Integrator ICs/Disabled'
 * '<S59>'  : 'ControllerTest/PID Controller/Integrator ICs/External IC'
 * '<S60>'  : 'ControllerTest/PID Controller/Integrator ICs/Internal IC'
 * '<S61>'  : 'ControllerTest/PID Controller/N Copy/Disabled'
 * '<S62>'  : 'ControllerTest/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S63>'  : 'ControllerTest/PID Controller/N Copy/External Parameters'
 * '<S64>'  : 'ControllerTest/PID Controller/N Copy/Internal Parameters'
 * '<S65>'  : 'ControllerTest/PID Controller/N Gain/Disabled'
 * '<S66>'  : 'ControllerTest/PID Controller/N Gain/External Parameters'
 * '<S67>'  : 'ControllerTest/PID Controller/N Gain/Internal Parameters'
 * '<S68>'  : 'ControllerTest/PID Controller/N Gain/Passthrough'
 * '<S69>'  : 'ControllerTest/PID Controller/P Copy/Disabled'
 * '<S70>'  : 'ControllerTest/PID Controller/P Copy/External Parameters Ideal'
 * '<S71>'  : 'ControllerTest/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S72>'  : 'ControllerTest/PID Controller/Parallel P Gain/Disabled'
 * '<S73>'  : 'ControllerTest/PID Controller/Parallel P Gain/External Parameters'
 * '<S74>'  : 'ControllerTest/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S75>'  : 'ControllerTest/PID Controller/Parallel P Gain/Passthrough'
 * '<S76>'  : 'ControllerTest/PID Controller/Reset Signal/Disabled'
 * '<S77>'  : 'ControllerTest/PID Controller/Reset Signal/External Reset'
 * '<S78>'  : 'ControllerTest/PID Controller/Saturation/Enabled'
 * '<S79>'  : 'ControllerTest/PID Controller/Saturation/Passthrough'
 * '<S80>'  : 'ControllerTest/PID Controller/Saturation Fdbk/Disabled'
 * '<S81>'  : 'ControllerTest/PID Controller/Saturation Fdbk/Enabled'
 * '<S82>'  : 'ControllerTest/PID Controller/Saturation Fdbk/Passthrough'
 * '<S83>'  : 'ControllerTest/PID Controller/Sum/Passthrough_I'
 * '<S84>'  : 'ControllerTest/PID Controller/Sum/Passthrough_P'
 * '<S85>'  : 'ControllerTest/PID Controller/Sum/Sum_PD'
 * '<S86>'  : 'ControllerTest/PID Controller/Sum/Sum_PI'
 * '<S87>'  : 'ControllerTest/PID Controller/Sum/Sum_PID'
 * '<S88>'  : 'ControllerTest/PID Controller/Sum Fdbk/Disabled'
 * '<S89>'  : 'ControllerTest/PID Controller/Sum Fdbk/Enabled'
 * '<S90>'  : 'ControllerTest/PID Controller/Sum Fdbk/Passthrough'
 * '<S91>'  : 'ControllerTest/PID Controller/Tracking Mode/Disabled'
 * '<S92>'  : 'ControllerTest/PID Controller/Tracking Mode/Enabled'
 * '<S93>'  : 'ControllerTest/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S94>'  : 'ControllerTest/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S95>'  : 'ControllerTest/PID Controller/postSat Signal/Feedback_Path'
 * '<S96>'  : 'ControllerTest/PID Controller/postSat Signal/Forward_Path'
 * '<S97>'  : 'ControllerTest/PID Controller/preSat Signal/Feedback_Path'
 * '<S98>'  : 'ControllerTest/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_ControllerTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
