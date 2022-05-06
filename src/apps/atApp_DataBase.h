/**
@file

*/
/*
  Application example t

  Library:: 

  This version is

  Copyright:: 2021 nguyentrinhtuan1996@gmail.com
*/

#ifndef _Application_atApp_DataBase_
#define _Application_atApp_DataBase_
/* _____PROJECT INCLUDES____________________________________________________ */
#include "App.h"
#include "../services/SD_Card/atService_uSD.h"
/* _____DEFINETIONS__________________________________________________________ */

/* _____GLOBAL VARIABLES_____________________________________________________ */
TaskHandle_t Task_atApp_DataBase;  
void atApp_DataBase_Task_Func(void *parameter);
///////////////////////////////////////////////Testing part//
/* _____GLOBAL FUNCTION______________________________________________________ */

/* _____CLASS DEFINITION_____________________________________________________ */

/**
 * This Application class is the application to manage the 
 */
class App_DataBase : public Application
{
public:
  	App_DataBase();
	~App_DataBase();

  // bool Write_To_File(char *file_name, char *data);
  // String Read_File(char *file_name);
    
protected:
	static void  App_DataBase_Pend();
	static void  App_DataBase_Start();
	static void  App_DataBase_Restart();
	static void  App_DataBase_Execute();
	static void  App_DataBase_Suspend();
	static void  App_DataBase_Resume();	  
	static void  App_DataBase_End();
private:
} atApp_DataBase ;
/**
 * This function will be automaticaly called when a object is created by this class
 */
App_DataBase::App_DataBase(/* args */)
{
  	_Pend_User 	     = *App_DataBase_Pend;
	_Start_User 	 = *App_DataBase_Start;
	_Restart_User 	 = *App_DataBase_Restart;
	_Execute_User 	 = *App_DataBase_Execute;
	_Suspend_User	 = *App_DataBase_Suspend;
	_Resume_User	 = *App_DataBase_Resume;
	_End_User	     = *App_DataBase_End;

	// change the ID of application
	ID_Application = 1;
	// change the application name
	Name_Application = (char*)"DataBase Application";
	// change the ID of SNM
}
/**
 * This function will be automaticaly called when the object of class is delete
 */
App_DataBase::~App_DataBase()
{
	
}
/**
 * Pend to start is the first task of this application it will do prerequisite condition. In the debit mode, task will send information of application to terminal to start the application.
 */
void  App_DataBase::App_DataBase_Pend()
{
    atService_uSD.Debug();
}
/**
 * This start function will init some critical function 
 */
void  App_DataBase::App_DataBase_Start()
{
	// init atXYZ Service in the fist running time
	atService_uSD.Run_Service();
  // atApp_DataBase.Write_To_File("/database","Hello");
  // atApp_DataBase.Read_File("/database");
}  
/**
 * Restart function of SNM  app
 */
void  App_DataBase::App_DataBase_Restart()
{

}
/**
 * Execute fuction of SNM app
 */
void  App_DataBase::App_DataBase_Execute()
{	
  atService_uSD.Run_Service();
  if(atApp_DataBase.User_Mode == APP_USER_MODE_DEBUG)
  {
  
  }   
}
void  App_DataBase::App_DataBase_Suspend(){}
void  App_DataBase::App_DataBase_Resume(){}	  
void  App_DataBase::App_DataBase_End(){}
// /**
//  * @brief 
//  * 
//  * @param file_name 
//  * @param data 
//  * @return 1 : successfull write
//  * @return 0 : failed write 
//  */
// bool App_DataBase::Write_To_File(char *file_name, char * data)
// {
//   File file = SD.open(file_name);
//   if(!file) {
//     if (atApp_DataBase.User_Mode == APP_USER_MODE_DEBUG)
//     {
//       Serial.println("File doesn't exist");
//       Serial.println("Creating file...");
//     }
//   }
//   else {
//     atService_uSD.appendFile(file_name,data);
//     return 1;
//   }
//   return 0;
// }
// /**
//  * @brief 
//  * 
//  * @param file_name 
//  * @return 0: failed read
//  */
// String App_DataBase::Read_File(char *file_name)
// {
//   if (atApp_DataBase.User_Mode == APP_USER_MODE_DEBUG)
//   {
//       Serial.printf("Reading file: %s\n", file_name);
//   }
//   File file = SD.open(file_name);
//   if(!file){
//       if (atApp_DataBase.User_Mode == APP_USER_MODE_DEBUG)
//       {
//           Serial.println("Failed to open file for reading");
//           return String(false);
//       }
//   }
//   String read_from_file;
//   while(file.available()){
//       read_from_file =  file.read();
//   }
//   file.close();
//   return read_from_file;
// }
void atApp_DataBase_Task_Func(void *parameter)
{
  while (1)
  {
    atApp_DataBase.Run_Application(APP_RUN_MODE_AUTO);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
#endif