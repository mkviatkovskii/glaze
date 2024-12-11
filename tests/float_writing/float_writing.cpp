#define UT_RUN_TIME_ONLY

#include "glaze/glaze.hpp"
#include "ut/ut.hpp"

using namespace ut;

void test_write_default() {
   std::vector<double> v = {1.0, 2.5};
   std::string buffer{};
   auto ec = glz::write_json(v, buffer);
   expect(ec == glz::error_code::none);
   expect(buffer == "[1,2.5]");
}

void test_write_whole_floats_as_floats_false() {
   std::vector<double> v = {1.0, 2.5};
   std::string buffer{};
   auto ec = glz::write<glz::opts{.write_whole_float_as_float = false}>(v, buffer);
   expect(ec == glz::error_code::none);
   expect(buffer == "[1,2.5]");
}

void test_write_whole_floats_as_floats_true() {
   std::vector<double> v = {1.0, 2.5};
   std::string buffer{};
   auto ec = glz::write<glz::opts{.write_whole_float_as_float = true}>(v, buffer);
   expect(ec == glz::error_code::none);
   expect(buffer == "[1.0,2.5]");
}

suite float_writing = [] {
   "write_default"_test = test_write_default;
   "write_whole_floats_as_floats_false"_test = test_write_whole_floats_as_floats_false;
   "write_whole_floats_as_floats_true"_test = test_write_whole_floats_as_floats_true;
};

int main() {
   return 0;
}
