Action()
{

	lr_start_transaction("1_transaction");

/*Correlation comment - Do not change!  Original value='1a6c5080fd7f47358d57d42db651a463' Name ='act_token' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=act_token",
		"RegExp=act=(.*?);",
		LAST);
		
	web_reg_find("Search=All",
		"Text/IC=MyTarget",
		LAST);

	web_url("mail.ru", 
		"URL=http://mail.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t91.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_transaction",LR_AUTO);

	
	
	
	
	
	
	
	
	
	
	
	
	lr_start_transaction("2_transaction");
	
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
		"Snapshot=t256.inf",
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
		"Name=page", "Value=https://e.mail.ru/messages/inbox?app_id_mytracker=58519&authid=lplgk5bh.5b&back=1&dwhsplit=s10273.b1ss12743s&from=login&x-login-auth=1", ENDITEM,
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
		"Referer=https://e.mail.ru/inbox/?app_id_mytracker=58519&authid={authid}&back=1%2C1&dwhsplit={dwhsplit}&from=login%2Cnavi&x-login-auth=1&afterReload=1",
		"Snapshot=t75.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=email", "Value={login}", ENDITEM,
		"Name=htmlencoded", "Value=false", ENDITEM,
		"Name=token", "Value={tokens}", ENDITEM,
		LAST);

	web_submit_data("add",
		"Action=https://e.mail.ru/api/v1/folders/add",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://e.mail.ru/inbox/?app_id_mytracker=58519&authid=lplgk5bh.5b&back=1%2C1&dwhsplit=s10273.b1ss12743s&from=login%2Cnavi&x-login-auth=1&afterReload=1",
		"Snapshot=t281.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=folders", "Value=[{\"name\":\"Folder#{randomValue}\",\"id\":null,\"system\":false,\"type\":\"\",\"parent\":-1,\"open\":true,\"security\":false,\"messages_total\":0,\"messages_unread\":0,\"child\":false,\"children\":false,\"archive\":false,\"collapse\":false,\"only_web\":false}]", ENDITEM,
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
		"Snapshot=t287.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("4_transaction",LR_AUTO);

	return 0;
}