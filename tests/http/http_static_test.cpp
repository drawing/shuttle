
#include "http_static_handler.h"

#include <gtest/gtest.h>

TEST(HTTPStaticHandler, Normal)
{
	HTTPStaticHandler router("/test/", "../http/data");

	HTTPRequest request;
	HTTPResponse response;

	request.set_uri("/test/static_1.html");
	int code = router.Process(request, response);
	EXPECT_EQ(code, 200);
	EXPECT_STREQ(response.get_header("Content-Type").c_str(), "text/html");
	EXPECT_STREQ(response.get_body().c_str(), "abc");

	request.set_uri("/test/static_2.html");
	code = router.Process(request, response);
	EXPECT_EQ(code, 404);

	HTTPStaticHandler router2("/test", "../http/data");
	request.set_uri("/test/static_1.html");
	code = router2.Process(request, response);
	EXPECT_EQ(code, 200);
	EXPECT_STREQ(response.get_header("Content-Type").c_str(), "text/html");
	EXPECT_STREQ(response.get_body().c_str(), "abc");
}

