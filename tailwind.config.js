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
            },
            fontFamily: {
                'perm': '"Permanent Marker", cursive',
                'corm': '"Cormorant SC", serif',
                'sche': 'Scheherazade, serif',
            },
            fontSize: {
                'hdr': '1.3rem',
                'exp': '1.7rem',
            },
            height: {
                'half-screen': '50vh',
            },
            maxWidth: {
                'harp': '1238px',
                'cont': '2000px',
            },
            spacing: {
                '60': '15rem',
                'cardw': '20rem',
                'cw-lg': '25rem',
                'cardh': '26rem',
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