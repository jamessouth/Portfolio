module.exports = {
    purge: [],
    theme: {
        extend: {
            backgroundImage: {
                'pe': "url('https://projecteuler.net/profile/jamessouth.png')",
                'cw': "url('https://www.codewars.com/users/jamessouth/badges/micro')",
                'cw-lg': "url('https://www.codewars.com/users/jamessouth/badges/large')",
            },
            colors: {
                'rosso-corsa': '#d00000',
                'indigo-dye': '#08415c',
                'mid-green': '#5b8c5a',
                'lite-gold-yellow': '#fafad2',
                'dk-sienna': '#2c0703',
                'id-lite': 'rgba(8, 65, 92, .15)',
                'mg-lite': 'rgba(91, 140, 90, .19)',
                'ds-lite': 'rgba(44, 7, 3, .16)',
                // oiuoiuh
                'dark-blue': '#405d82',
                'eerie-black': '#161616',
                'img-bg': '#e2e2e2',
            },
            fontFamily: {
                'cinz': 'Cinzel, serif',
                'corm': '"Cormorant SC", serif',
                'forum': 'Forum, cursive',
                'gara': 'EB Garamond, serif',
                'perm': '"Permanent Marker", cursive',
            },
            fontSize: {
                // 'hdr': '1.3rem',
                'first-letter': '5rem',
                'first-letter-big': '7rem',
            },
            height: {
                'half-screen': '50vh',
            },
            maxWidth: {
                'artw': '27.5rem',
                'cont': '2000px',
                'harp': '1238px',
            },
            spacing: {
                '60': '15rem',
                // 'cardw': '20rem',
                'cw-lg': '25rem',
            },
            screens: {
                'portrait': {
                    'raw': '(orientation: portrait)',
                },
                'wdk1': '440px',
            },
        },
    },
    variants: {},
    plugins: [],
}