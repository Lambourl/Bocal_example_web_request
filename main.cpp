#include <iostream>
#include <xxhr/xxhr.hpp>

using namespace std::string_literals;
int main(){
//! [Parameters-snippet]
  xxhr::GET("https://www.google.com/search"s, 

    // This will end up in the URI as : https://www.google.com/search?q=...&ie=...
    xxhr::Parameters{
      {"q", "xxhr c++ library"},
      {"ie", "utf-8"},
    }, 

    xxhr::on_response = [](auto&& resp) {
      std::cout << "What Google finds about this library : " << resp.text;
    });

  xxhr::POST("http://httpbin.org/post"s, 

    // This will end up in the URI as : http://httpbin.org/post?id=43&lang=en
    xxhr::Parameters{
      {"id", "43"},
      {"lang", "en"},
    },
    // While these params will be form-encoded parameters in the body
    xxhr::Body{
      xxhr::Parameters{
        {"parameter_name_in_body", "xxhr c++ library"},
        {"some_other_data", "As well in the HTTP body"},
      }
    }, 
    xxhr::on_response = [](auto&& resp) {
      std::cout << "Reply from httpbin to see passed parameters : " << resp.text;
    });
  return 0;
}