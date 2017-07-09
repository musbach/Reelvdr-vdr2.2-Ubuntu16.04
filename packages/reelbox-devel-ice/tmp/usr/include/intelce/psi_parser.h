/*
Copyright [2008] Intel Corporation

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/



#ifndef __PSI_PARSER_H
#define __PSI_PARSER_H

#include <stdbool.h>
#include <stdlib.h>

#define MAX_PROGRAMS                    24
#define MAX_STREAMS_PER_PROGRAM         8
#define MAX_BYTES_ES_INFO               1024 //technically a 10 bit number, could go to 1024

// Defines information for an elementary stream inside of a program
typedef struct {
    unsigned stream_type;     // Algorithm (mpeg2, ac3, etc...)
    unsigned es_pid;          // PID the demux need sto be set to to get this data
    unsigned es_info_length;  // 10 bit value specifying the size of the descriptors
    unsigned char  es_info[MAX_BYTES_ES_INFO]; //contains the ES info for parsing descriptor information
} pmt_stream_data_t;

typedef struct {
    unsigned pcr_pid;
    unsigned stream_count;
    pmt_stream_data_t streams[MAX_STREAMS_PER_PROGRAM];
    unsigned pmt_program_info_length;
} pmt_data_t;

typedef struct {
   unsigned program_number;
   unsigned pmt_pid;
} pmt_descriptor_t;

typedef struct {
    unsigned version_number;
    unsigned seciton_number;
    unsigned last_section_number;
    unsigned pmt_count;
    pmt_descriptor_t pmt_desc[MAX_PROGRAMS];
    unsigned nit_pid;
    bool nit_pid_valid;
} pat_data_t;

// This is designed to process a single PAT section only.  Must be called after the sections have been assembled.
// Returns true if parsing was completed without any errors, false otherwise.
bool parse_pat(pat_data_t *pat_data, void *buffer, size_t buffer_size);

// This is designed to process a single PMT section only.  Must be called after the sections have been assembled.
// Returns true if parsing was completed without any errors, false otherwise.
bool parse_pmt(pmt_data_t *pmt_data, void *buffer, size_t buffer_size);

#endif
