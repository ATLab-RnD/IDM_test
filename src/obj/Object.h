/**
@file
Object Template.
*/
/*
  Application_HMI.h - Arduino library for communicating with OP320A&S HMI
  over RS232/485 (via RTU protocol).

  Library:: chickyPig_OP320_V1

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/
#ifndef _Object_
#define _Object_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "Arduino.h"
/* _____GLOBAL VARIABLES_____________________________________________________ */

/* _____DEFINETIONS__________________________________________________________ */
 enum OBJ_State
  {
    OBJ_STATE_STARTING,
    OBJ_STATE_EXECUTING,
    OBJ_STATE_ENDING,
    OBJ_STATE_ERROR
  };
enum OBJ_User_Mode
  {
    OBJ_USER_MODE_NORMAL,
    OBJ_USER_MODE_DEBUG
  };
/* _____CLASS DEFINETION_____________________________________________________ */
/**
 * This Object class is base class for implement another class by inheritance 
 */
class Object
{
public:
  Object();
  void      Run_Object();
  // user can existing state of app by change Object_State into below state
 
  uint8_t Object_State = OBJ_STATE_STARTING;
  bool Step_Forward = 0;
protected:
  void (*_Start_User)();
  void (*_Execute_User)();
  void (*_End_User)();
  
  uint8_t   State_Object();
  char*     State_Object_String();
private:
  static const bool Run_Mode_Auto = 1;
  //  Tasks default of Object
  void Start(void);
  void Execute(void);
  void End(void);
};

/**
 */
Object::Object(void)
{
  _Start_User   = 0;
  _Execute_User = 0;
  _End_User     = 0;
}


/**
 * The main task of Object, need to bee call regularly for attack like a 
 * task in freertos. There are 3 state of an Object.  Starting is initing the prerequisite condition to
 * execute. Executing state is main state to hanble the task of Object. Object will finish all task and save all
 * parameter, srtop and remove all parameter. Error is the indicator for user when the 
 * Object is executing wrongly.
 * @param autoRun  Object_RUN_MODE_AUTO for auto execute and Object_RUN_MODE_MANNUAL for wait for execute manually by user
 */
void Object::Run_Object()
{
  switch (Object_State)
  {
    // starting the task
    case OBJ_STATE_STARTING:
      Start();
      break;

    //the task is executing 
    case OBJ_STATE_EXECUTING:
      Execute();
      break;

    // the task is been ending
    case OBJ_STATE_ENDING:
      End();
      break;

    // default
    default:

      break;
  }
}
/**
 * This function will return a unsigned integer of Object state at the present 
 * @return Object_State the
 */
uint8_t Object::State_Object()
{
  return Object_State;
}
char* Object::State_Object_String()
{
  switch (Object_State)
  {
  case OBJ_STATE_STARTING:
    return (char*)"Starting State";
    break;
  case OBJ_STATE_EXECUTING:
    return (char*)"Executing State";
    break;
  case OBJ_STATE_ENDING:
    return (char*)"Ending State";
    break;
  default:
    return (char*)"Error state";
    break;
  }
}
/**
 *  start is the fisrt task of this Object it will do prerequisite
 *  condition. In the debig mode, task will send information of Object to 
 * terminal to start the Object.
 * @param (*_End_User)() this function pointer will be define by user
 * @param User_Mode will be specified by user
 */
void Object::Start()
{
  // the user funciton
  (*_Start_User)();
  Object_State = OBJ_STATE_EXECUTING;
  Step_Forward = 1;
}
/**
 *  Pend to start is the fisrt task of this Object it will do prerequisite
 *  condition. In the debig mode, task will send information of Object to 
 * terminal to start the Object.
 * @param (*_End_User)() this function pointer will be define by user
 * @param User_Mode will be specified by user
 */
void Object::Execute()
{
  
  // the user funciton
  (*_Execute_User)();
  Step_Forward = 1;
}

/**
 *  Pend to start is the fisrt task of this Object it will do prerequisite
 *  condition. In the debig mode, task will send information of Object to 
 * terminal to start the Object.
 * @param (*_End_User)() this function pointer will be define by user
 * @param User_Mode will be specified by user
 */
void Object::End()
{
  // the user funciton
  (*_End_User)();
  Step_Forward = 1;
}

#endif