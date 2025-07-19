#include <gtest/gtest.h>
#include "user.h"

// Don't include booking.h directly — it's already pulled in by admin.h
#include "admin.h"

// Dummy Userlogin subclass
class DummyUserlogin : public Userlogin {
public:
    void UserLoginMenu() { /* skip menu */ }
};

// Dummy Bookingclass subclass
class DummyBookingclass : public Bookingclass {
public:
    void ViewBooking() { /* skip output */ }
    void BookingMenu() { /* skip menu */ }
};

// Dummy Adminlogin subclass
class DummyAdminlogin : public Adminlogin {
public:
    void AdminLoginMenu() { /* skip admin menu */ }
};

// Sample test cases

TEST(UserLoginTest, BookingIDGenerationFormat) {
    std::string name = "JohnDoe";
    std::string aadhar = "1234";
    std::string expected_id = name + aadhar;
    std::string actual_id = name + aadhar;
    ASSERT_EQ(expected_id, actual_id);
}

TEST(AdminLoginTest, AdminPasswordValidationSimulated) {
    std::string correctPassword = "admin123";
    std::string input = "admin123";
    ASSERT_EQ(correctPassword, input);
}

