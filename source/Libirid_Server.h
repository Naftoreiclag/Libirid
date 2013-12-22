/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LIBIRID_SERVER_H
#define LIBIRID_SERVER_H

class Libirid_Server
{
    public:
        Libirid_Server();
        ~Libirid_Server();

        // Initialize server
        void initialize();

        // Finalize server
        void finalize();

        // Executes a single tick in the expanse
        void doTick();
    protected:
    private:

};

#endif // LIBIRID_SERVER_H
