sort(int *arr)
{
    // Implementiamo un semplice bubble sort nemmeno tanto ottimizzato
    int lastSwapped = size;
    int countNSwap = 0;
    bool isSwap = true;
    for (int j = 0; j < size; j++)
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

    cout << "Numero di swap effettuati: " << countNSwap << endl;
}