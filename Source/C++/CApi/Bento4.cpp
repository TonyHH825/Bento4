/*****************************************************************
|
|    Bento4 - C API Implementation
|
|    Copyright 2002-2008 Gilles Boccon-Gibod & Julien Boeuf
|
|
|    This file is part of Bento4/AP4 (MP4 Atom Processing Library).
|
|    Unless you have obtained Bento4 under a difference license,
|    this version of Bento4 is Bento4|GPL.
|    Bento4|GPL is free software; you can redistribute it and/or modify
|    it under the terms of the GNU General Public License as published by
|    the Free Software Foundation; either version 2, or (at your option)
|    any later version.
|
|    Bento4|GPL is distributed in the hope that it will be useful,
|    but WITHOUT ANY WARRANTY; without even the implied warranty of
|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|    GNU General Public License for more details.
|
|    You should have received a copy of the GNU General Public License
|    along with Bento4|GPL; see the file COPYING.  If not, write to the
|    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
|    02111-1307, USA.
|
 ****************************************************************/

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "Bento4.h"
#include "Ap4.h"

/*----------------------------------------------------------------------
|   constants
+---------------------------------------------------------------------*/
const int AP4_FILE_BYTE_STREAM_MODE_READ       = AP4_FileByteStream::STREAM_MODE_READ;
const int AP4_FILE_BYTE_STREAM_MODE_WRITE      = AP4_FileByteStream::STREAM_MODE_WRITE;
const int AP4_FILE_BYTE_STREAM_MODE_READ_WRITE = AP4_FileByteStream::STREAM_MODE_READ_WRITE;

const int AP4_TRACK_TYPE_UNKNOWN = AP4_Track::TYPE_UNKNOWN;
const int AP4_TRACK_TYPE_AUDIO   = AP4_Track::TYPE_AUDIO;
const int AP4_TRACK_TYPE_VIDEO   = AP4_Track::TYPE_VIDEO;
const int AP4_TRACK_TYPE_SYSTEM  = AP4_Track::TYPE_SYSTEM;
const int AP4_TRACK_TYPE_HINT    = AP4_Track::TYPE_HINT;
const int AP4_TRACK_TYPE_TEXT    = AP4_Track::TYPE_TEXT;
const int AP4_TRACK_TYPE_JPEG    = AP4_Track::TYPE_JPEG;
const int AP4_TRACK_TYPE_RTP     = AP4_Track::TYPE_RTP;


/*----------------------------------------------------------------------
|   AP4_ByteStream implementation
+---------------------------------------------------------------------*/
void 
AP4_ByteStream_AddReference(AP4_ByteStream* self)
{
    self->AddReference();
}

void 
AP4_ByteStream_Release(AP4_ByteStream* self)
{
    self->Release();
}

AP4_Result 
AP4_ByteStream_ReadPartial(AP4_ByteStream*  self,
                           void*            buffer,
                           AP4_Size         bytes_to_read,
                           AP4_Size*        bytes_read)
{
    return self->ReadPartial(buffer, bytes_to_read, *bytes_read);
}

AP4_Result 
AP4_ByteStream_Read(AP4_ByteStream* self, 
                    void*           buffer, 
                    AP4_Size        bytes_to_read)
{
    return self->Read(buffer, bytes_to_read);
}

AP4_Result 
AP4_ByteStream_ReadDouble(AP4_ByteStream* self, double* value)
{
    return self->ReadDouble(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI64(AP4_ByteStream* self, AP4_UI64* value)
{
    return self->ReadUI64(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI32(AP4_ByteStream* self, AP4_UI32* value)
{
    return self->ReadUI32(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI24(AP4_ByteStream* self, AP4_UI32* value)
{
    return self->ReadUI24(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI16(AP4_ByteStream* self, AP4_UI16* value)
{
    return self->ReadUI16(*value);
}

AP4_Result 
AP4_ByteStream_ReadUI08(AP4_ByteStream* self, AP4_UI08* value)
{
    return self->ReadUI08(*value);
}

AP4_Result 
AP4_ByteStream_ReadString(AP4_ByteStream* self, 
                          char*           buffer, 
                          AP4_Size        size)
{
    return self->ReadString(buffer, size);
}

AP4_Result 
AP4_ByteStream_WritePartial(AP4_ByteStream* self,
                            const void*     buffer,
                            AP4_Size        bytes_to_write,
                            AP4_Size*       bytes_written)
{
    return self->WritePartial(buffer, bytes_to_write, *bytes_written);
}

AP4_Result
AP4_ByteStream_Write(AP4_ByteStream* self,
                     const void*     buffer,
                     AP4_Size        bytes_to_write)
{
    return self->Write(buffer, bytes_to_write);
}

AP4_Result 
AP4_ByteStream_WriteDouble(AP4_ByteStream* self, double value)
{
    return self->WriteDouble(value);
}

AP4_Result 
AP4_ByteStream_WriteUI64(AP4_ByteStream* self, AP4_UI64 value)
{
    return self->WriteUI64(value);
}

AP4_Result 
AP4_ByteStream_WriteUI32(AP4_ByteStream* self, AP4_UI32 value)
{
    return self->WriteUI32(value);
}

AP4_Result 
AP4_ByteStream_WriteUI24(AP4_ByteStream* self, AP4_UI32 value)
{
    return self->WriteUI24(value);
}

AP4_Result 
AP4_ByteStream_WriteUI16(AP4_ByteStream* self, AP4_UI16 value)
{
    return self->WriteUI16(value);
}

AP4_Result 
AP4_ByteStream_WriteUI08(AP4_ByteStream* self, AP4_UI08 value)
{
    return self->WriteUI08(value);
}

AP4_Result 
AP4_ByteStream_WriteString(AP4_ByteStream* self, const char* buffer)
{
    return self->WriteString(buffer);
}

AP4_Result 
AP4_ByteStream_Seek(AP4_ByteStream* self, AP4_Position position)
{
    return self->Seek(position);
}

AP4_Result 
AP4_ByteStream_Tell(AP4_ByteStream* self, AP4_Position* position)
{
    return self->Tell(*position);
}

AP4_Result
AP4_ByteStream_GetSize(AP4_ByteStream* self, AP4_LargeSize* size)
{
    return self->GetSize(*size);
}

AP4_Result 
AP4_ByteStream_CopyTo(AP4_ByteStream* self, 
                      AP4_ByteStream* receiver, 
                      AP4_LargeSize   size)
{
    return self->CopyTo(*receiver, size);
}

AP4_Result 
Ap4_ByteStream_Flush(AP4_ByteStream* self)
{
    return self->Flush();
}

AP4_ByteStream* 
AP4_SubStream_Create(AP4_ByteStream* container, 
                     AP4_Position     position, 
                     AP4_LargeSize    size)
{
    return new AP4_SubStream(*container, position, size);
}

AP4_ByteStream* 
AP4_MemoryByteStream_Create(AP4_Size size)
{
    return new AP4_MemoryByteStream(size);
}

AP4_ByteStream* 
AP4_MemoryByteStream_FromBuffer(const AP4_UI08* buffer, AP4_Size size)
{
    return new AP4_MemoryByteStream(buffer, size);
}

AP4_ByteStream*
AP4_MemoryByteStream_AdaptDataBuffer(AP4_DataBuffer* buffer)
{
    return new AP4_MemoryByteStream(*buffer);
}

AP4_ByteStream*
AP4_FileByteStream_Create(const char* name, int mode)
{
    return new AP4_FileByteStream(name, (AP4_FileByteStream::Mode) mode);
}

/*----------------------------------------------------------------------
|   AP4_DataBuffer implementation
+---------------------------------------------------------------------*/
AP4_Result 
AP4_DataBuffer_SetBuffer(AP4_DataBuffer* self, AP4_Byte* buffer, AP4_Size size)
{
    return self->SetBuffer(buffer, size);
}

AP4_Result 
AP4_DataBuffer_SetBufferSize(AP4_DataBuffer* self, AP4_Size size)
{
    return self->SetBufferSize(size);
}

AP4_Size 
AP4_DataBuffer_GetBufferSize(const AP4_DataBuffer* self)
{
    return self->GetBufferSize();
}

const AP4_Byte*
AP4_DataBuffer_GetData(const AP4_DataBuffer* self)
{
    return self->GetData();
}

AP4_Byte*
AP4_DataBuffer_UseData(AP4_DataBuffer* self)
{
    return self->UseData();
}

AP4_Size
AP4_DataBuffer_GetDataSize(const AP4_DataBuffer* self)
{
    return self->GetDataSize();
}

AP4_Result
AP4_DataBuffer_SetDataSize(AP4_DataBuffer* self, AP4_Size size)
{
    return self->SetDataSize(size);
}

AP4_Result
AP4_DataBuffer_SetData(AP4_DataBuffer* self, 
                      const AP4_Byte*  data, 
                      AP4_Size         data_size)
{
    return self->SetData(data, data_size);
}
                      
AP4_Result
AP4_DataBuffer_Reserve(AP4_DataBuffer* self, AP4_Size size)
{
    return self->Reserve(size);
}

AP4_DataBuffer*
AP4_DataBuffer_Create(AP4_Size size)
{
    return new AP4_DataBuffer(size);
}

AP4_DataBuffer*
AP4_DataBuffer_FromData(const void* data, AP4_Size data_size)
{
    return new AP4_DataBuffer(data, data_size);
}

AP4_DataBuffer*
AP4_DataBuffer_Clone(const AP4_DataBuffer* other)
{
    return new AP4_DataBuffer(*other);
}

/*----------------------------------------------------------------------
|   AP4_File implementation
+---------------------------------------------------------------------*/
AP4_Movie*
AP4_File_GetMovie(AP4_File* self)
{
    return self->GetMovie();
}

/* TODO AP4_File_GetFileType */

AP4_Result 
AP4_File_SetFileType(AP4_File*    self,
                     AP4_UI32     major_brand,
                     AP4_UI32     minor_version,
                     AP4_UI32*    compatible_brands,
                     AP4_Cardinal compatible_brand_count)
{
    return self->SetFileType(major_brand, 
                             minor_version,
                             compatible_brands,
                             compatible_brand_count);
}
                     
int
AP4_File_IsMoovBeforeMdat(const AP4_File* self)
{
    return (int) self->IsMoovBeforeMdat();
}

/* TODO AP4_File_Inspect */

const AP4_MetaData*
AP4_File_GetMetaData(AP4_File* self)
{
    return self->GetMetaData();
}

AP4_File*
AP4_File_Create(AP4_Movie* movie)
{
    return new AP4_File(movie);
}

AP4_File*
AP4_File_FromStream(AP4_ByteStream* stream, int moov_only)
{
    return new AP4_File(*stream, AP4_DefaultAtomFactory::Instance, moov_only); 
}

/*----------------------------------------------------------------------
|   AP4_Movie implementation
+---------------------------------------------------------------------*/
AP4_Cardinal
AP4_Movie_GetTrackCount(AP4_Movie* self)
{
    return self->GetTracks().ItemCount();
}

AP4_Track*
AP4_Movie_GetTrackByIndex(AP4_Movie* self, AP4_Ordinal index)
{
    AP4_Track* track = NULL;
    if (AP4_FAILED(self->GetTracks().Get(index, track))) {
        return NULL;
    } else {
        return track;
    }
}

AP4_Track*
AP4_Movie_GetTrackById(AP4_Movie* self, AP4_UI32 track_id)
{
    return self->GetTrack(track_id);
}

AP4_Track*
AP4_Movie_GetTrackByType(AP4_Movie* self, int type, AP4_Ordinal index)
{
    return self->GetTrack((AP4_Track::Type) type, index);
}

AP4_UI32
AP4_Movie_GetTimeScale(AP4_Movie* self)
{
    return self->GetTimeScale();
}

AP4_UI32
AP4_Movie_GetDuration(AP4_Movie* self)
{
    return self->GetDuration();
}

AP4_Duration
AP4_Movie_GetDurationMs(AP4_Movie* self)
{
    return self->GetDurationMs();
}

AP4_Movie*
AP4_Movie_Create(AP4_UI32 time_scale)
{
    return new AP4_Movie(time_scale);
}

