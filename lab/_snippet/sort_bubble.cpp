// TODO Ottimizzazione

template <typename T>
unsigned sort(T &arr, unsigned size)
{
    // Implementiamo un semplice bubble sort nemmeno tanto ottimizzato
    unsigned lastSwapped = size;
    unsigned countNSwap = 0;
    bool isSwap = true;
    for (int j = 0; j < sisze; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(i, i + 1);
                countNSwap++;
            }
        }
    }
    return countNSwap;
}