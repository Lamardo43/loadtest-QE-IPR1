Action()
{

	lr_start_transaction("1_transaction");

/*Correlation comment - Do not change!  Original value='94676dd8a6454c50a90efa0c8f8a76cc' Name ='act_token' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=act_token",
		"RegExp=act=(.*?);",
		LAST);
		
	web_reg_find("Search=All",
		"Text/IC=MyTarget",
		LAST);

	web_url("mail.ru", 
		"URL=https://mail.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t127.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_transaction",LR_AUTO);

	
	
	
	
	
	
	
	
	
	
	
	lr_start_transaction("2_transaction");

/*Correlation comment: Automatic rules - Do not change!  
Original value='s10273.b1ss12743c2s' 
Name ='dwhsplit' 
Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=dwhsplit",
		"RegExp=\"split\":\"(.*?)\"",
		"Ordinal=1",
		LAST);

	web_url("login_2", 
		"URL=https://account.mail.ru/login/?mode=simple&v=2.10.0&account_host=account.mail.ru&type=login&allow_external=1&app_id_mytracker=58519&success_redirect=https%3A%2F%2Fe.mail.ru%2Fmessages%2Finbox%3Fback%3D1&project=home&source=mailbox&from=navi&parent_url=https%3A%2F%2Fmail.ru%2F&responsive=compact", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.ru/", 
		"Snapshot=t138.inf", 
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
		"Snapshot=t148.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value={login}", ENDITEM,
		"Name=Login", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=Password", "Value={password}", ENDITEM,
		"Name=saveauth", "Value=1", ENDITEM,
		"Name=new_auth_form", "Value=1", ENDITEM,
		"Name=FromAccount", "Value=opener=account&allow_external=1&twoSteps=1", ENDITEM,
		"Name=act_token", "Value={act_token}", ENDITEM,
		"Name=page", "Value=https://e.mail.ru/messages/inbox?app_id_mytracker=58519&authid=lpmeem3v.qfg&back=1&dwhsplit={dwhsplit}&from=login&x-login-auth=1", ENDITEM,
		"Name=back", "Value=1", ENDITEM,
		"Name=lang", "Value=ru_RU", ENDITEM,
		LAST);

	lr_end_transaction("2_transaction",LR_AUTO);

	
	
	
	
	
	
	
	
	
	lr_start_transaction("3_transaction");
	
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
		"Referer=https://e.mail.ru/inbox/?app_id_mytracker={app_id_mytracker}&authid={authid}&back=1%2C1&dwhsplit={dwhsplit}&from=login%2Cnavi&x-login-auth=1&afterReload=1",
		"Snapshot=t75.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=email", "Value={login}", ENDITEM,
		"Name=htmlencoded", "Value=false", ENDITEM,
		"Name=token", "Value={some_token}", ENDITEM,
		LAST);

	web_submit_data("clear",
		"Action=https://e.mail.ru/api/v1/folders/clear",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://e.mail.ru/inbox/?app_id_mytracker=58519&authid=lpmeem3v.qfg&back=1%2C1&dwhsplit={dwhsplit}&from=login%2Cnavi&x-login-auth=1&afterReload=1",
		"Snapshot=t168.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=ids", "Value=[\"500002\"]", ENDITEM,
		"Name=email", "Value={login}", ENDITEM,
		"Name=htmlencoded", "Value=false", ENDITEM,
		"Name=token", "Value={token}", ENDITEM,
		LAST);

	lr_end_transaction("3_transaction",LR_AUTO);

	
	
	
	
	
	
	
	
	
	
	
	
	
	lr_start_transaction("4_transaction");
	
	web_reg_find("Search=All",
		"Text/IC=Status: 200",
		LAST);

	web_url("logout", 
		"URL=https://auth.mail.ru/cgi-bin/logout?next=1&lang=ru_RU&page=https%3A%2F%2Fmail.ru%2F%3Ffrom%3Dlogout", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://e.mail.ru/", 
		"Snapshot=t173.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("4_transaction",LR_AUTO);

	return 0;
}