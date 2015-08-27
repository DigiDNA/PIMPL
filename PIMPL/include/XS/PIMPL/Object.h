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
 * @brief       Declaration of the XS::PIMPL::Object template class
 */

#ifndef XSCPP_PIMPL_OBJECT_H
#define XSCPP_PIMPL_OBJECT_H

namespace XS
{
    namespace PIMPL
    {
        /*!
         * @brief           Generic PIMPL class
         * @tparam          T   The class extending XS::PIMPL::Object
         */
        template< class T >
        class Object
        {
            public:
                
                /*!
                 * @brief       Class constructor
                 */
                template< typename ... A > 
                Object( A ... args );
                
                /*!
                 * @brief       Class copy constructor
                 * @param       o   Another object to be used as data source for the initialization
                 */
                Object( const Object & o );
                
                /*!
                 * @brief       Class move constructor
                 * @param       o   Another object to be used as data source for the initialization
                 */
                Object( Object && o );
                
                /*!
                 * @brief       Class destructor
                 */
                virtual ~Object( void );
                
                /*!
                 * @brief       Assignment operator
                 * @param       o   Another object to use as data source
                 */
                Object< T > & operator =( Object o );
                
                /*!
                 * @brief           ADL - Swap function for XS::PIMPL::Object
                 * @tparam          U   The class extending XS::PIMPL::Object
                 * @param           o1  The first object to swap
                 * @param           o2  The second object to swap
                 */
                template< class U >
                friend void swap( Object< U > & o1, Object< U > & o2 );
                
            private:
                
                friend T;
                class  IMPL;
                
                /*!
                 * @brief           Deleter class for the private implementation
                 */
                class D
                {
                    public:
                        
                        /*!
                         * @brief       Function call operator
                         * @param       p   The private implementation pointer that needs to be deleted
                         * 
                         * This method shall be defined manually for all classes
                         * extending XS::PIMPL::Object, as there is no way to
                         * delete a pointer to a forward class.
                         */
                        void operator ()( IMPL * p );
                };
                
                /*!
                 * @brief       A pointer to the class' private implementation
                 */
                std::unique_ptr< IMPL, D > impl;
        };
    }
}

#endif /* XSCPP_PIMPL_OBJECT_H */
