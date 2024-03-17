def merge_sort(v):
    if len(v) == 1:
        return v
        
    l = merge_sort(v[:len(v) // 2])
    r = merge_sort(v[len(v) // 2:])

    merged = []
    i = j = 0

    while i < len(l) and j < len(r):
        if l[i] < r[j]:
            merged.append(l[i])
            i += 1
        else:
            merged.append(r[j])
            j += 1

    merged.extend(l[i:])
    merged.extend(r[j:])

    return merged
