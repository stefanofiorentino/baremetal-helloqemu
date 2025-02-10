#define STEP_0 0
#define STEP_1 1
#define STEP_2 2
#define STEP_3 3
#define STEP_4 4
#define CURRENT_STEP STEP_0

#if CURRENT_STEP == STEP_0
#include "step0.hpp"
#elif CURRENT_STEP == STEP_1
#include "step1.hpp"
#elif CURRENT_STEP == STEP_2
#include "step2.hpp"
#elif CURRENT_STEP == STEP_3
#include "step3.hpp"
#elif CURRENT_STEP == STEP_4
#include "step4.hpp"
#endif 
