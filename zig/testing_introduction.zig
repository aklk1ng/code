const std = @import("std");

fn addOne(number: i32) i32 {
    return number + 1;
}

test addOne {
    try std.testing.expect(addOne(41) == 42);
}

test "expect addOne adds one to 41" {
    // The Standard Library contains useful functions to help create tests.
    // `expect` is a function that verifies its argument is true.
    // It will return an error if its argument is false to indicate a failure.
    // `try` is used to return an error to the test runner to notify it that the test failed.
    try std.testing.expect(addOne(41) == 42);
}
