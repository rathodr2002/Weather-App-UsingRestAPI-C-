#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

int main()
{
	cout << "O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O--O-O "<<endl; 
	cout << "\t\t My Weather App" << endl;
	cout << "Enter City Name: ";
	string city;
	getline(cin,city);
	
	http_client client(U("https://api.openweathermap.org/data/2.5"));

	uri_builder builder(U("/weather"));

	builder.append_query(U("q"),utility::conversions::to_string_t(city));
	builder.append_query(U("appid"),U("3c86c2a09b6401c1bb6cc4483cd96b22"));

	http_request req(methods::GET);
	req.set_request_uri(builder.to_string());

	client.request(req).then([](http_response response) {
			return response.extract_json();
		}
	).then([](web::json::value body) {
			cout << "\t Temperature : " << body[U("main")][U("temp")].as_double() << " K" << endl;
			cout << "\t  Sky : " << body[U("main")][U("humidity")].as_double() <<" %" << endl;
			cout << "\t Weather : " << utility::conversions::to_utf8string(body[U("weather")][0][U("main")].as_string()) << endl;
		}
	).wait();

	cout << "O-O-O-O-O-O-O-O-O-O-O-O-O-O-O-O--O-O "<<endl; 
	return 0;
}