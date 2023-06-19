const print = std.debug.print;
const std = @import("std");
const os = std.os;
const assert = std.debug.assert;

pub fn main() void {
    // integers
    const one_plus_one: i32 = 1 + 1;
    print("{}\n", .{one_plus_one});

    // floats
    const seven_div_three: f32 = 7.0 / 3.0;
    print("{}\n", .{seven_div_three});

    // boolean
    print("{}\n{}\n{}", .{
        true and false,
        true or false,
        !true,
    });

    // optional
    var optional_value: ?[]const u8 = null;
    assert(optional_value == null);

    print("\noptional type: {}\nvalue: {?s}\n", .{ @TypeOf(optional_value), optional_value });

    optional_value = "hi";
    assert(optional_value != null);

    print("\noptional type: {}\nvalue: {?s}\n", .{ @TypeOf(optional_value), optional_value });

    // error union
    var number_or_error: anyerror!i32 = error.ArgNotFound;

    print("\nerror union type: {}\nvalue: {!}\n", .{ @TypeOf(number_or_error), number_or_error });

    number_or_error = 1234;
    print("\nerror union type: {}\nvalue: {!}\n", .{ @TypeOf(number_or_error), number_or_error });
}
