import { Providers } from './providers'
import { Layout } from '../components/Layout'

import './globals.css'

export const metadata = {
  title: {
    template: '%s - Darby Huye',
    default:
      'Darby Huye - Researcher, working to increase visibility in the cloud.',
  },
  description:
    'xx1',
  alternates: {
    types: {
      'application/rss+xml': `${process.env.NEXT_PUBLIC_SITE_URL}/feed.xml`,
    },
  },
}

export default function RootLayout({ children }) {
  return (
    <html lang="en" className="h-full antialiased" suppressHydrationWarning>
      <body className="flex h-full bg-zinc-50 dark:bg-black">
        <Providers>
          <div className="flex w-full">
            <Layout>{children}</Layout>
          </div>
        </Providers>
      </body>
    </html>
  )
}
