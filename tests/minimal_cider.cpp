#include "catch.hpp"
#include <zmq.hpp>

TEST_CASE("Minimal cider passes attempt to talk via zeromq", "[positive]") {
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("inproc://test");
    sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    bool const passed{true};
    REQUIRE(passed);
}
