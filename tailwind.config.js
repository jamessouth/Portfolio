module.exports = {
    future: {
        purgeLayersByDefault: true,
    },
    corePlugins: {
        animation: false,
    },
    purge: [
        './index.html',
        './src/*.bs.js',
    ],
    theme: {
        extend: {
            backgroundImage: {
                'pe': "url('https://projecteuler.net/profile/jamessouth.png')",
                'cw': "url('https://www.codewars.com/users/jamessouth/badges/micro')",
                'cw-lg': "url('https://www.codewars.com/users/jamessouth/badges/large')",
            },
            colors: {
                'dark-blue': '#405d82',
                'eerie-black': '#161616',
                'img-bg': '#e2e2e2',
            },
            fontFamily: {
                'cinz': 'Cinzel, serif',
                'corm': '"Cormorant SC", serif',
                'forum': 'Forum, cursive',
                'gara': 'EB Garamond, serif',
            },
            height: {
                'half-screen': '50vh',
            },
            maxWidth: {
                'artw': '16rem',
                'cont': '2000px',
            },
            spacing: {
                'iconw': '39px',
                'iconh': '37px',
                'cw-lg': '25rem',
            },
            screens: {
                'portrait': {
                    'raw': '(orientation: portrait)',
                },
                'landscape500': {
                    'raw': '(orientation: landscape) and (min-height: 500px)',
                },
                'wdk1': '440px',
            },
        },
    },
    variants: {},
    plugins: [],
}