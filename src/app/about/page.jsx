import Image from 'next/image'
import Link from 'next/link'
import clsx from 'clsx'

import { Container } from '@/components/Container'
import {
  GitHubIcon,
  InstagramIcon,
  LinkedInIcon,
  TwitterIcon,
} from '@/components/SocialIcons'
import portraitImage from '@/images/portrait.jpg'


function SocialLink({ className, href, children, icon: Icon }) {
  return (
    <li className={clsx(className, 'flex')}>
      <Link
        href={href}
        className="group flex text-sm font-medium text-zinc-800 transition hover:text-teal-500 dark:text-zinc-200 dark:hover:text-teal-500"
      >
        <Icon className="h-6 w-6 flex-none fill-zinc-500 transition group-hover:fill-teal-500" />
        <span className="ml-4">{children}</span>
      </Link>
    </li>
  )
}

function MailIcon(props) {
  return (
    <svg viewBox="0 0 24 24" aria-hidden="true" {...props}>
      <path
        fillRule="evenodd"
        d="M6 5a3 3 0 0 0-3 3v8a3 3 0 0 0 3 3h12a3 3 0 0 0 3-3V8a3 3 0 0 0-3-3H6Zm.245 2.187a.75.75 0 0 0-.99 1.126l6.25 5.5a.75.75 0 0 0 .99 0l6.25-5.5a.75.75 0 0 0-.99-1.126L12 12.251 6.245 7.187Z"
      />
    </svg>
  )
}

export const metadata = {
  title: 'About',
  description:
    'I’m Spencer Sharp. I live in New York City, where I design the future.',
}

export default function About() {
  return (
    <Container className="mt-16 sm:mt-32">
      <div className="grid grid-cols-1 gap-y-16 lg:grid-cols-2 lg:grid-rows-[auto_1fr] lg:gap-y-12">
        <div className="lg:pl-20">
          <div className="max-w-xs px-2.5 lg:max-w-none">
            <Image
              src={portraitImage}
              alt=""
              sizes="(min-width: 1024px) 32rem, 20rem"
              className="aspect-square rotate-3 rounded-2xl bg-zinc-100 object-cover dark:bg-zinc-800"
            />
          </div>
        </div>
        <div className="lg:order-first lg:row-span-2">
          <h1 className="text-4xl font-bold tracking-tight text-zinc-800 dark:text-zinc-100 sm:text-5xl">
            I’m Darby Huye. I live in Boston, where I research observability in the cloud.
          </h1>
          <div className="mt-6 space-y-7 text-base text-zinc-600 dark:text-zinc-400">
            <p>
              I'm a third year Ph.D. Candidate in the <a href='https://docclab.cs.tufts.edu/index.html' style={{ color: '#3f57a1' }}>D.O.C.C. Lab</a> at Tufts University studying under the guidance of <a href="https://raja.cs.tufts.edu/" style={{ color: '#3f57a1' }}> Professor Raja Sambasivan</a>. My research interests involve leveraging distributed tracing for debugging performance problems in cloud-based systems. 
            </p>
            <p>The first portion of my Ph.D. research was centered on understanding the buzzword <i>microservices</i>. I (along with my colleagues) conducted a user-study interviewing folks in industry and academia about their experiences with microservice-based applications. We found that the assumptions around this buzzword and the open-source academic testbed applications are far too limited to enable robust research in this space. This lead me to an internship at Meta, where I had the opportunity to analyze aspects of their microservice applications. My findings were published at ATC '23 and a portion of the data was released on <a href='https://github.com/facebookresearch/distributed_traces' style={{ color: '#3f57a1' }}>github</a>.</p>
            <p> I am working on chapter two of my Ph.D. which is investigating: 'how can we capture meaningful observability data in our systems?' Prior research in this space assumes perfect observability (or ignores the possibility of imperfect data), which is far from the reality at many large organizations. I plan to investigate how we can make decisions regarding the performance of a distributed system given imperfect tracing data.
            </p>
            <p>
              Beyond research, I try to spend most of my time outdoors hiking or kayaking. I also dabble in sewing (peep some of my sewing projects <a href='https://www.instagram.com/darbysews/' style={{ color: '#3f57a1' }}>here</a>).
            </p>
          </div>
        </div>
        <div className="lg:pl-20">
          <ul role="list">
            <SocialLink href="https://github.com/darbyhuye" icon={GitHubIcon} className="mt-4">
              Follow on GitHub
            </SocialLink>
            <SocialLink href="https://www.linkedin.com/in/darby-huye-a98b76160/" icon={LinkedInIcon} className="mt-4">
              Follow on LinkedIn
            </SocialLink>
            <SocialLink
              href="mailto:darby.huye@tufts.edu"
              icon={MailIcon}
              className="mt-8 border-t border-zinc-100 pt-8 dark:border-zinc-700/40"
            >
              darby.huye@tufts.edu
            </SocialLink>
          </ul>
        </div>
      </div>
    </Container>
  )
}
