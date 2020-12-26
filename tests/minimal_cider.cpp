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

TEST_CASE("We use the expected zeromq version", "[positive]") {
    int major, minor, patch;
    zmq::version(&major, &minor, &patch);
    CHECK(patch == 4);
    CHECK(minor == 3);
    REQUIRE(major == 4);
}
