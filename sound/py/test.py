from scipy import fftpack

def calc_fft(data_array, N_ave):
    fft_array = []

    for i in range(N_ave):
        fft_array.append(fftpack.fft(data_array[i]))
    return fft_array

def create_masks(powers, threshold):
    masks = []

    for powers_per_frame in powers:
        flags = []

        for power in powers_per_frame:
            if (power >= threshold):
                flags.append(1.0)
            else:
                flags.append(0.0)
        masks.append(flags)
    return masks

# // npの配列なら単純に mask * test_fftでOK
# expected_sounds = [x * y for (x, y) in zip(masks, test_fft)]

def calc_ifft(fft_array, N_ave, Fs):
    ifft_array = []

    for i in range(N_ave):
        ifft_array.append(fftpack.ifft(fft_array[i]).real)
    return ifft_array

def write_wav(ifft_array, path, samplerate): 
    w = wave.Wave_write(path)
    w.setnchannels(1)
    w.setsampwidth(2)
    w.setframerate(samplerate)
    w.writeframes(ifft_array)
    w.close()

# ファイル書き込み
path = '../output/{}_teian3_{}_frame.wav'
write_wav(targets_ifft, path.format(input_path, threshold), samplerate)
