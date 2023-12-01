#include <stdio.h>
#include <time.h>

int getCurrentSecondWithOffset(int offset) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    return  (tm_info->tm_hour * 3600 + tm_info->tm_min * 60 + tm_info->tm_sec) + offset;
}

Action()
{
	
	int X = atoi(lr_eval_string("{randomValue}"));
	lr_save_int(getCurrentSecondWithOffset(X), "currentSecondWithOffset");

	lr_start_transaction("1_mainPage");

/*Correlation comment: Automatic rules - Do not change!  
Original value='030bfcfdcd99428584cc0789c619e8f6' 888
Name ='act_token' 
Type ='Rule' 
AppName ='mail' 
RuleName ='act_token'*/
	web_reg_save_param_regexp(
		"ParamName=act_token",
		"RegExp=act=(.*?);",
		LAST);

	web_reg_find("Search=All",
		"Text/IC=MyTarget",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='58519' 
Name ='app_id_mytracker' 
Type ='Rule' 
AppName ='mail' 
RuleName ='app_ig_mytracker'*/
	web_reg_save_param_regexp(
		"ParamName=app_id_mytracker",
		"RegExp=\"appIdMytracker\":\\ \"(.*?)\"",
		LAST);

	web_url("mail.ru", 
		"URL=https://mail.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction("1_mainPage",LR_AUTO);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	lr_start_transaction("2_login");

	/*Correlation comment - Do not change!  Original value='s10273.b1ss12743s' Name ='dwhsplit' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=dwhsplit",
		"RegExp=\"split\":\"(.*?)\"",
		LAST);
	
	web_url("login",
		"URL=https://account.mail.ru/login/?mode=simple&v=2.10.0&account_host=account.mail.ru&type=login&allow_external=1&app_id_mytracker={app_id_mytracker}&success_redirect=https%3A%2F%2Fe.mail.ru%2Fmessages%2Finbox%3Fback%3D1&project=home&source=mailbox&from=navi&parent_url=https%3A%2F%2Fmail.ru%2F&responsive=compact",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://mail.ru/",
		"Snapshot=t137.inf",
		"Mode=HTML",
		LAST);

	web_reg_find("Search=All",
		"Text/IC=Status: 200",
		LAST);



	web_submit_data("auth",
		"Action=https://auth.mail.ru/cgi-bin/auth?from=navi",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://account.mail.ru/",
		"Snapshot=t45.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value={logins}", ENDITEM,
		"Name=Login", "Value={logins}", ENDITEM,
		"Name=password", "Value={passwords}", ENDITEM,
		"Name=Password", "Value={passwords}", ENDITEM,
		"Name=saveauth", "Value=1", ENDITEM,
		"Name=new_auth_form", "Value=1", ENDITEM,
		"Name=FromAccount", "Value=opener=account&allow_external=1&twoSteps=1", ENDITEM,
		"Name=act_token", "Value={act_token}", ENDITEM,
		"Name=page", "Value=https://e.mail.ru/messages/inbox?app_id_mytracker={app_id_mytracker}&authid={ParamAuthid}&back=1&dwhsplit={dwhsplit}&from=login&x-login-auth=1", ENDITEM,
		"Name=back", "Value=1", ENDITEM,
		"Name=lang", "Value=ru_RU", ENDITEM,
		LAST);

	lr_end_transaction("2_login",LR_AUTO);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	lr_start_transaction("3_message");
	
	
	/*Correlation comment: Automatic rules - Do not change!  
	Original value='fa4dd2844c8d13dc0b5e043fe01c3876:RZmq8vauWZw-RHLhy4014OGUikaHqZuggG2BvCIg6xF7InRpbWUiOjE2OTQ2MzkxMjgsInR5cGUiOiJjc3JmIiwibm9uY2UiOiIxZWJlMmNmOWViYzAwYjRmIn0' 
	Name ='token' 
	Type ='Rule' 
	AppName ='mail' 
	RuleName ='token_2'*/
	web_reg_save_param_regexp(
		"ParamName=token",
		"RegExp=\"token\":\"(.*?)\"",
		LAST);
	
	web_reg_find("Search=All",
		"Text/IC=birthday",
		LAST);
	
	web_submit_data("short_2",
		"Action=https://e.mail.ru/api/v1/user/short",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://e.mail.ru/inbox/?app_id_mytracker={app_id_mytracker}&authid={ParamAuthid}&back=1%2C1&dwhsplit={dwhsplit}&from=login%2Cnavi&x-login-auth=1&afterReload=1",
		"Snapshot=t75.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=email", "Value={logins}", ENDITEM,
		"Name=htmlencoded", "Value=false", ENDITEM,
		"Name=token", "Value={ParamToken}", ENDITEM,
		LAST);

	web_reg_find("Search=All",
		"Text/IC=\"status\":200",
		LAST);

	web_submit_data("send",
		"Action=https://e.mail.ru/api/v1/k8s/messages/send",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://e.mail.ru/inbox/?app_id_mytracker={app_id_mytracker}&authid={ParamAuthid}&back=1%2C1&dwhsplit={dwhsplit}&from=login%2Cnavi&x-login-auth=1&afterReload=1",
		"Snapshot=t82.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=ATTACHMENTS_RESTORE", "Value=true", ENDITEM,
		"Name=ATTACHMENTS_EXPIRATION_TIME", "Value=14400000", ENDITEM,
		"Name=id", "Value={ParamId}", ENDITEM,
		"Name=source", "Value={\"draft\":\"\",\"reply\":\"\",\"forward\":\"\",\"schedule\":\"\"}", ENDITEM,
		"Name=headers", "Value={}", ENDITEM,
		"Name=template", "Value=0", ENDITEM,
		"Name=sign", "Value=0", ENDITEM,
		"Name=remind", "Value=0", ENDITEM,
		"Name=receipt", "Value=false", ENDITEM,
		"Name=subject", "Value={themes}", ENDITEM,
		"Name=priority", "Value=3", ENDITEM,
		"Name=send_date", "Value=", ENDITEM,
		"Name=body", "Value={\"html\":\"<div>{messages}_{currentSecondWithOffset}</div><div>&nbsp;</div><div>--<br>{underText}</div>\",\"text\":\"{messages}_{timestamp}\\n"
		"\\n"
		"\\n"
		"--\\n"
		"{underText}\"}", ENDITEM,
		"Name=from", "Value=Гримерные Зеркала <{logins}>", ENDITEM,
		"Name=correspondents", "Value={\"to\":\"{owners} <{owners}>\",\"cc\":\"\",\"bcc\":\"\"}", ENDITEM,
		"Name=folder_id", "Value=", ENDITEM,
		"Name=triggerModelChangePlease", "Value=true", ENDITEM,
		"Name=compose_stat", "Value={\"user_track\":\"m|362|445|2|1;m|209|167|1|0;m|203|8|1|0;m|200|133|1|1;m|206|78|1|0;m|1896|6|1|1;m|211|20|1|1;c|118|0|406|104;m|283|70|1|1;m|201|10|1|0;m|200|8|1|0;c|78|0|350|103;m|3580|1|1|1;m|204|142|1|1;m|201|6|1|0;c|64|0|309|237;m|149|24|1|1;m|204|1|1|0;m|2851|6|1|1;m|204|362|2|1;m|205|18|1|0;m|205|2|1|0;c|598|0|264|626\",\"build\":\"release-fmail-21810.1970-01-03T06_03_37\",\"serverTime\":1694518767253}", ENDITEM,
		"Name=delay_for_cancellation", "Value=true", ENDITEM,
		"Name=attaches", "Value={\"list\":[]}", ENDITEM,
		"Name=email", "Value={logins}", ENDITEM,
		"Name=htmlencoded", "Value=false", ENDITEM,
		"Name=token", "Value={token}", ENDITEM,
		LAST);
	

	lr_end_transaction("3_message",LR_AUTO);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	lr_start_transaction("4_logout");
	
	web_reg_find("Search=All",
		"Text/IC=Status: 200",
		LAST);
	
	web_url("logout", 
		"URL=https://auth.mail.ru/cgi-bin/logout?next=1&lang=ru_RU&page=https%3A%2F%2Fmail.ru%2F%3Ffrom%3Dlogout", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://e.mail.ru/", 
		"Snapshot=t91.inf", 
		"Mode=HTML", 
		LAST);
	

	lr_end_transaction("4_logout",LR_AUTO);

	return 0;
}