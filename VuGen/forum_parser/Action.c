Action()
{
	
	web_reg_save_param_regexp("ParamName=postDate",
      	"RegExp=<p class=\"commentPostTime post\">(.*?)</p>",
	    "Ordinal=1",
	    LAST
   	);
	
//	web_reg_save_param("postDate",
//	    "LB=<p class=\"commentPostTime post\">",
//	    "RB=</p>",
//	    "Ord=1",
//	    LAST
//   );
//	

	web_reg_save_param_regexp("ParamName=firstCommentText",
      	"RegExp=<p class=\"commentText\">(.*?)</p>",
	    "Ordinal=1",
	    LAST
   	);

//	
//	web_reg_save_param("firstCommentText",
//	    "LB=<p class=\"commentText\">",
//	    "RB=</p>",
//	    "Ord=1",
//	    LAST
//   );
//	
	web_reg_save_param_regexp("ParamName=commentsCount",
      	"RegExp=<h2>Comments \((.*?)\)</h2>",
	    "Ordinal=1",
	    LAST
   	);

//	web_reg_save_param("commentsCount",
//	    "LB=<h2>Comments (",
//	    "RB=)",
//	    "Ord=1",
//	    LAST
//   );
//
	web_reg_save_param_regexp("ParamName=firstUser",
      	"RegExp=<p class=\"user\">(.*?)</p>",
	    "Ordinal=1",
	    LAST
   	);

//	web_reg_save_param("firstUser",
//	    "LB=<p class=\"user\">",
//	    "RB=</p>",
//	    "Ord=1",
//	    LAST
//   );
//	
	web_reg_save_param_regexp("ParamName=users",
      	"RegExp=<p class=\"user\">(.*?)</p>",
	    "Ordinal=All",
	    LAST
   	);

//	
//	web_reg_save_param("users",
//	    "LB=<p class=\"user\">",
//	    "RB=</p>",
//	    "Ord=All",
//	    LAST
//   );
//	

	web_reg_save_param_regexp("ParamName=commentLink",
      	"RegExp=<a class=\"addComment\" href=\"(.*?)\">",
	    "Ordinal=1",
	    LAST
   	);

//		
//	web_reg_save_param("commentLink",
//	    "LB=<a class=\"addComment\" href=\"",
//	    "RB=\">",
//	    "Ord=1",
//	    LAST
//   );
//	
		
	web_url("getHTML",
		"URL={URL}",
	    "Resource=0",
	    "RecContentType=text/html",
	    "Referer=",
	    "Snapshot=t1.inf",
	    LAST
	);



	return 0;
}