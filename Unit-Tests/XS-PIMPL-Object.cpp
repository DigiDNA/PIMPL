/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com
 * @brief       Test case XS::PIMPL::Object
 */

/* Disabled warinngs for GoogleMock */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( XS_PIMPL_Object, FooClassGetter )
{
    Foo f;
    
    ASSERT_EQ( 0, f.GetX() );
    ASSERT_EQ( 0, f.GetY() );
}

TEST( XS_PIMPL_Object, FooClassSetter )
{
    Foo f;
    
    f.SetX( 1 );
    f.SetY( 2 );
    
    ASSERT_EQ( 1, f.GetX() );
    ASSERT_EQ( 2, f.GetY() );
}

TEST( XS_PIMPL_Object, FooClassConstructorWithParams )
{
    Foo f( 1, 2 );
    
    ASSERT_EQ( 1, f.GetX() );
    ASSERT_EQ( 2, f.GetY() );
}

TEST( XS_PIMPL_Object, FooClassCopyConstructor )
{
    Foo f1( 1, 2 );
    Foo f2( f1 );
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, FooClassMoveConstructor )
{
    Foo f1( 1, 2 );
    Foo f2 = std::move( f1 );
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, FooClassAssigmnentOperator )
{
    Foo f1( 1, 2 );
    Foo f2;
    
    f2 = f1;
    
    ASSERT_EQ( 1, f2.GetX() );
    ASSERT_EQ( 2, f2.GetY() );
}

TEST( XS_PIMPL_Object, BarClassGetter )
{
    Bar b;
    
    ASSERT_EQ( 0, b.GetX() );
    ASSERT_EQ( 0, b.GetY() );
    ASSERT_EQ( 0, b.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassSetter )
{
    Bar b;
    
    b.SetX( 1 );
    b.SetY( 2 );
    b.SetZ( 3 );
    
    ASSERT_EQ( 1, b.GetX() );
    ASSERT_EQ( 2, b.GetY() );
    ASSERT_EQ( 3, b.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassConstructorWithParams )
{
    Bar b( 1, 2, 3 );
    
    ASSERT_EQ( 1, b.GetX() );
    ASSERT_EQ( 2, b.GetY() );
    ASSERT_EQ( 3, b.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassCopyConstructor )
{
    Bar b1( 1, 2, 3 );
    Bar b2( d1 );
    
    ASSERT_EQ( 1, b2.GetX() );
    ASSERT_EQ( 2, b2.GetY() );
    ASSERT_EQ( 3, b2.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassMoveConstructor )
{
    Bar b1( 1, 2, 3 );
    Bar b2 = std::move( b1 );
    
    ASSERT_EQ( 1, b2.GetX() );
    ASSERT_EQ( 2, b2.GetY() );
    ASSERT_EQ( 3, b2.GetZ() );
}

TEST( XS_PIMPL_Object, BarClassAssigmnetOperator )
{
    Bar b1( 1, 2, 3 );
    Bar b2;
    
    b2 = b1;
    
    ASSERT_EQ( 1, b2.GetX() );
    ASSERT_EQ( 2, b2.GetY() );
    ASSERT_EQ( 3, b2.GetZ() );
}
