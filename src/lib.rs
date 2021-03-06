use std::ffi::CStr;
use std::os::raw::c_char;

#[no_mangle]
pub extern fn intentional_panic(message: *const c_char) {
    panic!("{}", unsafe { CStr::from_ptr(message) }.to_string_lossy());
}
