//-----------------------------------------------------------------------------
// Copyright (c) 2015-2016 Marcelo Fernandez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef __OGG_H__
#define __OGG_H__

class oggFile : public audioFile {
private:
	void *vf;

	int format;
	int channels;
	int samplesPerSec;
	int bitsPerSample;
	int totalSamples;

	int currentSection;
public:
	oggFile(oamlFileCallbacks *cbs);
	~oggFile();

	int GetFormat() const { return format; }
	int GetChannels() const { return channels; }
	int GetSamplesPerSec() const { return samplesPerSec; }
	int GetBitsPerSample() const { return bitsPerSample; }
	int GetBytesPerSample() const { return bitsPerSample / 8; }
	int GetTotalSamples() const { return totalSamples; }

	void WriteToFile(const char *filename, ByteBuffer *buffer, int channels, unsigned int sampleRate, int bytesPerSample);

	int Open(const char *filename);
	int Read(ByteBuffer *buffer, int size);

	void Close();
};

#endif /* __OGG_H__ */
