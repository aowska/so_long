/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:09:43 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/02 21:09:44 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_so_long.h"

#define WIDTH 800
#define HEIGHT 600

int main ()
{
    ft_map();
    void *mlx_ptr;
    void *win_ptr;

    // Inicjalizacja MinilibX
    mlx_ptr = mlx_init();
    if (!mlx_ptr) {
        return -1;  // Błąd inicjalizacji
    }

    // Tworzenie nowego okna
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "My Game");
    if (!win_ptr) {
        return -1;  // Błąd tworzenia okna
    }

    // Rysowanie czerwonego piksela w środku okna
    mlx_pixel_put(mlx_ptr, win_ptr, WIDTH / 2, HEIGHT / 2, 0xFF0000);

    // Uruchomienie pętli zdarzeń MinilibX
    mlx_loop(mlx_ptr);

    return 0;
}