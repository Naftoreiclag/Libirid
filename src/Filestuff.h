/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef FILESTUFF_H
#define FILESTUFF_H

// If we are in debug,
#ifdef DEBUG
// {
        // Use the path local to the .cbp file
        #define getLocalFilePath(j) "../bin/"j
// }
#else
// {
        // Use the path local to the .exe file
        #define getLocalFilePath(j) j
// }
#endif

#endif // FILESTUFF_H
